#include <stdio.h>
#include "binarySearchTree.h"

int main(void) {

    node *root = NULL;

    root = addNode(root, 10);
    root = addNode(root, 20);
    root = addNode(root, 5);
    root = addNode(root, 3);
    root = addNode(root, 40);
    root = addNode(root, 6);
    root = addNode(root, 15);
    root = addNode(root, 7);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Search 5: %d\n", search(root, 5));
    printf("Search 40: %d\n", search(root, 40));
    printf("Search 200: %d\n", search(root, 200));

    printf("Maximum: %d\n", max(root));
    printf("Minimum: %d\n", min(root));

    root = deleteNode(root, 10);
    root = deleteNode(root, 5);
    root = deleteNode(root, 40);

    printf("After Deletion - Inorder: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}