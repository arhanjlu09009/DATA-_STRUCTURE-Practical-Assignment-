#include <stdio.h>

int matrix[5][5] = {0};  // 5 vertices

void addEdge(int u, int v) {
    matrix[u][v] = 1;
    matrix[v][u] = 1;  // undirected graph
}

void displayMatrix() {
    int i, j;
    printf("Adjacency Matrix:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);
    addEdge(3, 4);
    
    displayMatrix();
    return 0;
}
