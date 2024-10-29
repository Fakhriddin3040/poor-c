#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define HASH_TABLE_SIZE 1000


typedef struct KeyValue {
    char *key;
    int value;
    struct KeyValue *next;
} KeyValue;


typedef KeyValue* HashTable;


HashTable hashTable[HASH_TABLE_SIZE] = {NULL};

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


void insert(const char *key, int value) {
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

    int index = hash(key);


   if(hashTable[index] == NULL) {
        hashTable[index] = newPair;
   } else {
        newPair->next = hashTable[index];
        hashTable[index] = newPair;
   }
}


int search(const char *key) {
    unsigned long int index = hash(key);
    KeyValue *entry = hashTable[index];

    while(entry != NULL) {
        if(strcmp(entry->key, key) == 0) {
            return entry->value;
        }
        entry = entry->next;
    }
    return -1;
}


void freeHashTable(HashTable *hashTable, size_t size) {
    KeyValue *entry;
    unsigned int i = 0;
    while(i != size) {

        entry = hashTable[i];

        while(entry != NULL) {
            KeyValue *tmp = entry;
            entry = entry->next;
            free(tmp->key);
            free(tmp);
        }

        i++;
    }
}


int main(int argc, char const *argv[]) {
    return 0;
}
