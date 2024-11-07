#include <stdio.h>
#include <stdlib.h>


#define ASCII_TABLE_SIZE 127
#define CHAR_TO_DIGIT_MAPPING_SIZE 10


char char_to_digit_mapping[CHAR_TO_DIGIT_MAPPING_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};


typedef struct Node {
    int val;
    struct Node *next;
} Node;


char int_from_char(char value) {
    if(CHAR_TO_DIGIT_MAPPING_SIZE < value) {
        return -1;
    }
    return char_to_digit_mapping[value];
}


size_t get_linked_list_len(Node *node) {
    size_t i = 0;
    while(node->next != NULL) {
        node = node->next;
        i++;
    }
    return i;
}


Node* reverse_nodes(Node *node) {
    size_t list_len = get_linked_list_len(node);
    return NULL;
}


int main(void) {

        printf("%d", 10 % (int)11e100 == 0);
    return 0;
}