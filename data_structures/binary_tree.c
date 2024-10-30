#include <stdio.h>
#include <stdlib.h>

#define NODE_MEM_ALL_ERR_KEY 83209247


typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;


typedef struct BinTree {
    struct Node *root;

    int (*insert)(struct BinTree *, Node **, int);
    struct Node* (*create_node)(int);
    struct Node* (*search)(struct BinTree *, struct Node *, int);
} BinTree;


Node* create_node(int data){
    Node *new_node = malloc(sizeof(Node));

    if(new_node == NULL) {
        fprintf(stderr, "Memory allocation for Node is failed.");
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


int insert_node(BinTree *tree, Node **root, int data) {
    if(*(root) == NULL) {
        *root = tree->create_node(data);
        return EXIT_SUCCESS;
    }
    if((*root)->data < data) {
        return tree->insert(tree, &((*root)->right), data);
    }
    if((*root)->data > data) {
        return tree->insert(tree, &((*root)->left), data);
    }
    return EXIT_FAILURE;
}


Node* search(BinTree *tree, Node *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        return root;
    }
    if(root->data < data) {
        return tree->search(tree, root->right, data);
    }
    return tree->search(tree, root->left, data);
}


BinTree* create_binary_tree(void) {
    BinTree *tree = malloc(sizeof(BinTree));

    tree->create_node = create_node;
    tree->insert = insert_node;
    tree->search = search;

    tree->root = tree->create_node(1000);

    return tree;
}


int main(void) {
    BinTree *tree = create_binary_tree();

    tree->insert(tree, &(tree->root), 69);
    tree->insert(tree, &(tree->root), 70);
    tree->insert(tree, &(tree->root), 43);

    Node *first_value = tree->search(tree, tree->root, 69);
    Node *second_value = tree->search(tree, tree->root, 70);
    Node *third_value = tree->search(tree, tree->root, 43);
    Node *null_value = tree->search(tree, tree->root, 3432);

    printf("Success");

    return 0;
} 