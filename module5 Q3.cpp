#include <stdio.h>
#include <stdlib.h>

int queue[10], front = -1, rear = -1;
int visited[5] = {0};
int graph[5][5] = {{0,1,1,0,0},
                   {1,0,0,1,0},
                   {1,0,0,1,0},
                   {0,1,1,0,1},
                   {0,0,0,1,0}};

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[++front];
}

void BFS(int start) {
    int v, i;
    enqueue(start);
    visited[start] = 1;
    
    printf("BFS: %d ", start);
    
    while (front != rear) {
        v = dequeue();
        for (i = 0; i < 5; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
                printf("%d ", i);
            }
        }
    }
}

int main() {
    BFS(0);
    printf("\n");
    return 0;
}
