#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void displayTree(struct Node *root) {
    if (root == NULL) return;
    
    printf("Root: %d\n", root->data);
    if (root->left)
        printf("Left: %d\n", root->left->data);
    else
        printf("Left: NULL\n");
    if (root->right)
        printf("Right: %d\n", root->right->data);
    else
        printf("Right: NULL\n");
}

int main() {
    struct Node *root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    
    displayTree(root);
    return 0;
}
