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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insertBST(struct Node *root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    return root;
}

int findMin(struct Node *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node *root) {
    while (root && root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node *root = NULL;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 80);
    
    printf("Minimum: %d\n", findMin(root));
    printf("Maximum: %d\n", findMax(root));
    
    return 0;
}
