 #include <stdio.h>
 #define MAX 20
int stack[MAX], top = -1;
 int visited[MAX];
 // Push onto stack
 void push(int v) {
    stack[++top] = v;
 }
 // Pop from stack
 int pop() {
    if (top == -1) return -1;
    return stack[top--];
 }
 // DFS using stack
 void DFS(int adj[MAX][MAX], int n, int start) {
    int i, v;
    for (i = 0; i < n; i++) visited[i] = 0;
    push(start);
    printf("DFS Traversal starting from vertex %d: ", start);
    while (top != -1) {
        v = pop();
        if (!visited[v]) {
            printf("%d ", v);
            visited[v] = 1;
            // Push neighbors in reverse order so smaller index is visited first
            for (i = n - 1; i >= 0; i--) {
                if (adj[v][i] == 1 && !visited[i]) {
                    push(i);
                }
            }
        }
    }
    printf("\n");
 }
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
    DFS(adj, n, start);
    return 0;
 }
