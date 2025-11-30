#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int x) {      // helper
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void search(int key) {
    struct Node *temp = head;
    int pos = 1, found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        printf("Element %d not found in list\n", key);
}

int main() {
    int x;
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    printf("Enter element to search: ");
    scanf("%d", &x);

    search(x);

    return 0;
}
