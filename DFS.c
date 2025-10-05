#include <stdio.h>

int n, G[10][10], visited[10];

void DFS(int i) {
    int j;
    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < n; j++) {
        if (!visited[j] && G[i][j] == 1) {
            DFS(j);
        }
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 0; i < n; i++) visited[i] = 0;

    printf("Enter start vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}