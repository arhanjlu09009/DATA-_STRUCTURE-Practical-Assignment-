#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *graph[5];  // 5 vertices

void addEdge(int u, int v) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void displayList() {
    int i;
    struct Node *temp;
    
    for (i = 0; i < 5; i++) {
        printf("Vertex %d: ", i);
        temp = graph[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    
    displayList();
    return 0;
}
