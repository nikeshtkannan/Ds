#include <stdio.h>

int n, G[10][10], visited[10];
int queue[10], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == 9) return; // queue full
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void BFS(int start) {
    int i, u;
    visited[start] = 1;
    enqueue(start);

    printf("BFS Traversal: ");
    while (!isEmpty()) {
        u = dequeue();
        printf("%d ", u);

        for (i = 0; i < n; i++) {
            if (G[u][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
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

    BFS(start);

    return 0;
}