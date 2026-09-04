#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node;

node *addNode(node *root, int data);

void preOrderTraversal(node *root);
void inorderTraversal(node *root);
void postOrderTraversal(node *root);

int search(node *root, int data);

int max(node *root);
int min(node *root);

node *deleteNode(node *root, int data);

#endif