#include <stdio.h>
#include <stdlib.h>

#define MAX 100



void bfs_single_component(int graph[MAX][MAX], int visited[MAX], int start, int n) {
    int queue[MAX];
    int front = 0, rear = 0, count = 0; 

    visited[start] = 1;
    queue[rear] = start;
    rear = (rear + 1) % MAX;
    count++;

    while (count > 0) {
        int current = queue[front];
        front = (front + 1) % MAX;
        count--;

        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                if (count == MAX) {
                    fprintf(stderr, "Queue overflow: increase MAX\n");
                    exit(EXIT_FAILURE);
                }
                visited[i] = 1;
                queue[rear] = i;
                rear = (rear + 1) % MAX;
                count++;
            }
        }
    }
}

void bfs_full(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};

    printf("BFS Traversal starting from %d (component): ", start);
    bfs_single_component(graph, visited, start, n);
    printf("\n");

    printf("BFS Traversal covering all vertices: ");
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            bfs_single_component(graph, visited, v, n);
        }
    }
    printf("\n");
}

int main(void) {
    int graph[MAX][MAX];
    int n, start;

    printf("Enter the number of vertices (<= %d): ", MAX);
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0 || n > MAX) {
        printf("Invalid n. Must be 1..%d\n", MAX);
        return 0;
    }

    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1) return 0;
        }
    }

    printf("Enter the starting vertex (0..%d): ", n - 1);
    if (scanf("%d", &start) != 1) return 0;
    if (start < 0 || start >= n) {
        printf("Invalid start vertex. Must be between 0 and %d.\n", n - 1);
        return 0;
    }

    

    bfs_full(graph, n, start);

    return 0;
}
