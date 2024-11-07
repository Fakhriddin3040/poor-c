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
    Node* (*create_node)(int);
    Node* (*search)(struct BinTree *,Node *, int);
    Node* (*get_max)(struct BinTree *, Node *);
    Node* (*get_min)(struct BinTree *, Node *);
    void* (*delete)(struct BinTree*, Node **, int);
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


Node* delete_node(BinTree *this, Node **root, int data) {
    if(*root == NULL) {
        return NULL;
    }
    else if((*root)->data > data) return this->delete(this, &((*root)->left), data);
    else if((*root)->data < data) return this->delete(this, &((*root)->right), data);
    else {
        if((*root)->right == NULL || (*root)->left == NULL) {
            *root = ((*root)->right == NULL) ? (*root)->left : (*root)->right; 
        }
        else {
            Node *max_in_left = this->get_max(this, (*root)->left);
            (*root)->data = max_in_left->data;
            (*root)->left = this->delete(this, &((*root)->left), max_in_left->data);
        }
    }
    return *root;
}


Node* get_max(BinTree *tree, Node *root) {
    if(tree->root == NULL) {
        return NULL;
    }
    if(tree->root->right == NULL) {
        return tree->root;
    }
    return get_max(tree, root->right);
}


Node* get_min(BinTree *tree, Node *root) {
    if(tree->root == NULL) {
        return NULL;
    }
    if(tree->root->left == NULL) {
        return tree->root;
    }
    return get_min(tree, root->left);
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
    tree->get_max = get_max;
    tree->get_min = get_min;

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