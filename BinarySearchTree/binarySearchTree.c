#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

node *addNode(node *root, int data) {

    if (root == NULL) {

        node *temp = malloc(sizeof(node));

        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    if (root->data < data) {
        root->right = addNode(root->right, data);
        return root;
    }

    root->left = addNode(root->left, data);

    return root;
}


void preOrderTraversal(node *root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


void inorderTraversal(node *root) {

    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);

    printf("%d ", root->data);

    inorderTraversal(root->right);
}


void postOrderTraversal(node *root) {

    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    printf("%d ", root->data);
}


int search(node *root, int data) {

    if (root == NULL) {
        return -1;
    }

    if (root->data == data) {
        return 1;
    }

    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}


int max(node *root) {

    if (root == NULL) {
        return 0;
    }

    while (root->right != NULL) {
        root = root->right;
    }

    return root->data;
}


int min(node *root) {

    if (root == NULL) {
        return 0;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}


node *deleteNode(node *root, int data) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {

        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        if (root->right != NULL) {

            int successor = min(root->right);

            root->data = successor;
            root->right = deleteNode(root->right, successor);

            return root;
        }

        int predecessor = max(root->left);

        root->data = predecessor;
        root->left = deleteNode(root->left, predecessor);

        return root;
    }

    if (root->data < data) {
        root->right = deleteNode(root->right, data);
        return root;
    }

    root->left = deleteNode(root->left, data);

    return root;
}