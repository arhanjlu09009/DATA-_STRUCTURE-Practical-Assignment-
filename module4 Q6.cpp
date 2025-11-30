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

struct Node *searchBST(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    
    if (key < root->data)
        return searchBST(root->left, key);
    
    return searchBST(root->right, key);
}

int main() {
    struct Node *root = NULL;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    
    int key = 30;
    if (searchBST(root, key))
        printf("%d found in BST\n", key);
    else
        printf("%d not found in BST\n", key);
    
    return 0;
}
