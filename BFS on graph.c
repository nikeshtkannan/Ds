#include <stdio.h>
#define MAX 20

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Enqueue
void enqueue(int v) {
    if (rear == MAX - 1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear)
        return -1; // Empty queue
    return queue[front++];
}

// BFS function
void BFS(int adj[MAX][MAX], int n, int start) {
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while ((v = dequeue()) != -1) {
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Main function
int main() {
    int n, adj[MAX][MAX], start;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, n, start);
    return 0;
}
