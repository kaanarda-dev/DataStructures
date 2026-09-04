#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int data;
    struct Node *left;
    struct Node *right;

}node;


struct Node *addNode(struct Node* root, int data) {

    if (root == NULL) {

        node* temp = (node*)malloc(sizeof(node));
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
void preOrderTraversal(struct Node *root) {

    if (root == NULL) {
        return;
    }
    printf("%d ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void inorderTraversal(struct Node *root) {

    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);


}

void postOrderTraversal(struct Node *root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ",root->data);
}


int search(struct Node *root, int data) {
    if (root == NULL) {
        return -1;
    }

    if (root->data == data) {
        return 1;
    }

    if (search(root->left, data) == 1) {
        return 1;
    }

    if (search(root->right, data) == 1) {
        return 1;
    }

    return -1;

}

int max(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    while (root->right != NULL) {
        root = root->right;

    }
    return root->data;

}

int min(struct Node *root) {
    if (root == NULL) {
        return 0;
    }

    while (root->left != NULL) {
        root = root->left;

    }
    return root->data;

}

struct Node *deleteNode(struct Node *root, int data) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {

        if (root->left == NULL && root->right == NULL) {
            return NULL;
        }

        if (root->right != NULL) {
            root -> data = min(root -> right);
            root->right = deleteNode(root -> right, min(root->right));
            return root;
        }

        root -> data = max(root -> left);
        root -> left = deleteNode(root -> left, max(root -> left));
        return root;

    }
    if (root->data < data) {
        root->right = deleteNode(root->right, data);
        return root;
    }

    root->left = deleteNode(root->left, data);
    return root;


}

int main() {


    node *root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 20);
    root = addNode(root, 5);
    root = addNode(root, 3);
    root = addNode(root, 40);
    root = addNode(root, 6);
    root = addNode(root, 15);
    root = addNode(root, 7);
    inorderTraversal(root);

    printf("\n");

    printf("%d\n", search(root, 5));
    printf("%d\n", search(root, 40));
    printf("%d\n", search(root, 200));

    printf("%d\n", max(root));
    printf("%d\n", min(root));

    root = deleteNode(root, 10);
    root = deleteNode(root, 5);
    root = deleteNode(root, 40);
    inorderTraversal(root);
    printf("\n");


    preOrderTraversal(root);
    printf("\n");

    postOrderTraversal(root);
    printf("\n");


    return 0;
}