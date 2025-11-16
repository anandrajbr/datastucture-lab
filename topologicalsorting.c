#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int V; 
    int adj[MAX_VERTICES][MAX_VERTICES];
    int in_degree[MAX_VERTICES];
};

void createGraph(struct Graph* graph, int V) {
    graph->V = V;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adj[i][j] = 0;
        }
        graph->in_degree[i] = 0;
    }
}

void addEdge(struct Graph* graph, int u, int v) {
    if (u < 0 || u >= graph->V || v < 0 || v >= graph->V) {
        fprintf(stderr, "addEdge: invalid vertices %d -> %d (valid range 0..%d)\n", u, v, graph->V - 1);
        return;
    }
    if (graph->adj[u][v] == 0) {            
        graph->adj[u][v] = 1;               
        graph->in_degree[v]++;            
    }
}

void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int queue[MAX_VERTICES], front = 0, rear = 0;
    int top_order[MAX_VERTICES];
    int count = 0;

    int in_deg[MAX_VERTICES];
    for (int i = 0; i < V; i++) in_deg[i] = graph->in_degree[i];

    for (int i = 0; i < V; i++) {
        if (in_deg[i] == 0) {
            if (rear == MAX_VERTICES) { 
                fprintf(stderr, "Queue overflow (increase MAX_VERTICES)\n");
                return;
            }
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int u = queue[front++];
        top_order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (graph->adj[u][v]) {
                in_deg[v]--;
                if (in_deg[v] == 0) {
                    if (rear == MAX_VERTICES) {
                        fprintf(stderr, "Queue overflow (increase MAX_VERTICES)\n");
                        return;
                    }
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != V) {
        printf("There exists a cycle in the graph — topological ordering not possible.\n");
        printf("Vertices with non-zero in-degree (part of a cycle or unreachable): ");
        for (int i = 0; i < V; i++) {
            if (in_deg[i] != 0) printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("Topological Sort (one valid ordering): ");
        for (int i = 0; i < count; i++) {
            printf("%d%c", top_order[i], (i + 1 == count) ? '\n' : ' ');
        }
    }
}

int main(void) {
    int V, E;
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    if (scanf("%d", &V) != 1) return 0;
    if (V <= 0 || V > MAX_VERTICES) {
        printf("Invalid number of vertices. Must be 1..%d\n", MAX_VERTICES);
        return 0;
    }

    printf("Enter the number of directed edges: ");
    if (scanf("%d", &E) != 1) return 0;
    if (E < 0) {
        printf("Invalid number of edges.\n");
        return 0;
    }

    struct Graph graph;
    createGraph(&graph, V);

    printf("Enter the edges (u v) one per line, meaning an edge from u to v.\n");
    printf("Vertices must be numbered 0 to %d (0-based indexing).\n", V - 1);
    for (int i = 0; i < E; i++) {
        int u, v;
        if (scanf("%d %d", &u, &v) != 2) {
            fprintf(stderr, "Invalid input for edge %d\n", i + 1);
            return 0;
        }
        if (u < 0 || u >= V || v < 0 || v >= V) {
            fprintf(stderr, "Invalid edge %d: (%d, %d) — valid range is 0..%d\n", i + 1, u, v, V - 1);
            return 0;
        }
        addEdge(&graph, u, v);
    }

    topologicalSort(&graph);
    return 0;
}
