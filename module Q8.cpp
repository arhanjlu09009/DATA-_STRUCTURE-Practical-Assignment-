#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode *start = NULL;

void createDoublyList(int n) {
    int i, x;
    struct DNode *newNode, *temp;
    start = NULL;

    for (i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &x);

        newNode = (struct DNode*)malloc(sizeof(struct DNode));
        newNode->data = x;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (start == NULL) {
            start = newNode;
        } else {
            temp = start;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void displayDoublyList() {
    struct DNode *temp = start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Doubly list: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);

    createDoublyList(n);
    displayDoublyList();

    return 0;
}
