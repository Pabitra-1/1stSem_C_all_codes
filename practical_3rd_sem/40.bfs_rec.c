#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = 0;
int rear = -1;

void bfsRecursive(int n) {
    int vertex, i;

    if (front > rear)
        return;

    vertex = queue[front++];

    printf("%d ", vertex);

    for (i = 0; i < n; i++) {

        if (graph[vertex][i] == 1 && !visited[i]) {

            visited[i] = 1;

            queue[++rear] = i;
        }
    }

    bfsRecursive(n);
}

int main() {
    int n, edges, u, v;
    int start, i;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices!\n");
        return 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge!\n");
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= n) {
        printf("Invalid starting vertex!\n");
        return 0;
    }

    visited[start] = 1;
    queue[++rear] = start;

    printf("BFS Traversal: ");

    bfsRecursive(n);

    printf("\n");

    return 0;
}