#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HASH_TABLE_SIZE 1000
#define HASH_TABLE_KEY_NOT_FOUND -0111111111
#define HASH_TABLE_MEM_ALL_ERR_MSG \
        "Memory allocation failed for HashTable\n"


typedef struct KeyValue {
    char *key;
    int value;
    struct KeyValue *next;
} KeyValue;

typedef struct HashTable {
    KeyValue **table;
    struct KeyValue* (*search)(struct HashTable *, const char *);
    int (*insert)(struct HashTable *, const char *, int);
    int (*hash)(const char *);
    void (*free)(struct HashTable *);
} HashTable;


KeyValue* getLatestPair(KeyValue *pair) {
    while(pair->next != NULL) {
        pair = pair->next;
    }
    return pair;
}

int hash(const char *key) {
    unsigned long int hashValue = 0;
    unsigned int i = 0;

    while(key[i] != '\0') {
        hashValue += hashValue * 37 + key[i];
        i++;
    }

    return hashValue % HASH_TABLE_SIZE;
}


int insert(HashTable *this, const char *key, int value) {
    KeyValue *newPair = malloc(sizeof(KeyValue));

    if(newPair == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newPair->key = strdup(key);

    if(newPair->key == NULL) {
        fprintf(stderr, "Memory allocation for key copy failed\n");
        exit(EXIT_FAILURE);
    }

    newPair->value = value;
    newPair->next = NULL;

    int index = this->hash(key);


   if(this->table[index] == NULL) {
        this->table[index] = newPair;
   } else {
        newPair->next = this->table[index];
        this->table[index] = newPair;
   }
   return 0;
}


KeyValue* search(HashTable *this, const char *key) {
    int index = this->hash(key);
    KeyValue *entry = this->table[index];

    while(entry != NULL) {
        if(strcmp(entry->key, key) == 0) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}


void freeHashTable(HashTable *this) {
    KeyValue *entry;
    unsigned int i = 0;
    while(i != HASH_TABLE_SIZE) {

        entry = this->table[i];

        while(entry != NULL) {
            KeyValue *tmp = entry;
            entry = entry->next;
            free(tmp->key);
            free(tmp);
        }
        i++;
    }
    free(this->table);
    free(this);
}

HashTable* init_hash_table(void) {
    HashTable *table = malloc(sizeof(HashTable));

    if(table == NULL) {
        fprintf(stderr, HASH_TABLE_MEM_ALL_ERR_MSG);
        exit(EXIT_FAILURE);
    }

    table->table = malloc(sizeof(KeyValue *) * HASH_TABLE_SIZE);

    if(table->table == NULL) {
        fprintf(stderr, HASH_TABLE_MEM_ALL_ERR_MSG);
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < HASH_TABLE_SIZE; i++) {
        table->table[i] = NULL;
    }

    table->search = search;
    table->insert = insert;
    table->hash = hash;
    table->free = freeHashTable;

    return table;
}


int main(void) {
    HashTable *hash_table = init_hash_table();

    hash_table->insert(hash_table, "first", 8249);
    hash_table->insert(hash_table, "second", 39289);

    KeyValue *target1 = hash_table->search(hash_table, "first");
    KeyValue *target2 = hash_table->search(hash_table, "second");
    KeyValue *null_target = hash_table->search(hash_table, "unknown");

    if (target1) {
        printf("Key: first, Value: %d\n", target1->value);
    }
    if (target2) {
        printf("Key: second, Value: %d\n", target2->value);
    }
    if (!null_target) {
        printf("Key 'unknown' not found.\n");
    }

    hash_table->free(hash_table);  // Освобождаем память перед выходом
    return 0;
}
