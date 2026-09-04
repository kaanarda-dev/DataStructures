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

void inorderTraversal(struct Node *root) {

    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);


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


int main() {


    node *root = NULL;
    root = addNode(root, 10);
    root = addNode(root, 20);
    root = addNode(root, 5);
    root = addNode(root, 3);
    root = addNode(root, 40);
    inorderTraversal(root);

    printf("\n");
    printf("%d\n", search(root, 5));
    printf("%d\n", search(root, 40));
    printf("%d\n", search(root, 200));
    return 0;
}