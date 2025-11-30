#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int x) {          // helper to create list
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

void deleteFromBeginning() {
    struct Node *temp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void displayList() {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    printf("Before deletion:\n");
    displayList();

    deleteFromBeginning();

    printf("After deletion:\n");
    displayList();

    return 0;
}
