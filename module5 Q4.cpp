#include <stdio.h>

int visited[5] = {0};
int graph[5][5] = {{0,1,1,0,0},
                   {1,0,0,1,0},
                   {1,0,0,1,0},
                   {0,1,1,0,1},
                   {0,0,0,1,0}};

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    
    int i;
    for (i = 0; i < 5; i++) {
        if (graph[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}

int main() {
    printf("DFS: ");
    DFS(0);
    printf("\n");
    return 0;
}
