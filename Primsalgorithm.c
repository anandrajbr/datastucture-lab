#include <stdio.h>
#include <stdlib.h>

#define MAX 20    
#define INF 1000000

int main(void) {
    int vertex_array[MAX];
    int visited[MAX];
    int cost_matrix[MAX][MAX];
    int vertex_count;
    int row, column, counter;

    printf("Total no of vertices (<= %d): ", MAX - 1);
    if (scanf("%d", &vertex_count) != 1) return 0;
    if (vertex_count <= 0 || vertex_count >= MAX) {
        printf("Invalid number of vertices. Use 1..%d\n", MAX - 1);
        return 0;
    }

    printf("\n-- Enter vertex labels (one per line) --\n");
    for (counter = 1; counter <= vertex_count; counter++) {
        printf("vertex[%d]: ", counter);
        if (scanf("%d", &vertex_array[counter]) != 1) return 0;
    }

    printf("\n--- Enter Cost matrix of size %d x %d ---\n", vertex_count, vertex_count);
    printf("(Enter 0 for no edge / no direct connection)\n");
    for (row = 1; row <= vertex_count; row++) {
        for (column = 1; column <= vertex_count; column++) {
            if (scanf("%d", &cost_matrix[row][column]) != 1) return 0;
            if (row == column) {
                cost_matrix[row][column] = INF; 
            } else if (cost_matrix[row][column] == 0) {
                cost_matrix[row][column] = INF; 
            }
        }
    }

    for (row = 1; row <= vertex_count; row++) visited[row] = 0;

    visited[1] = 1;

    int edge_count = vertex_count - 1;
    int count = 0;          
    int sum_cost = 0;

    printf("\nSelected edges in MST (Prim's):\n");
    while (count < edge_count) {
        int min_cost = INF;
        int sel_u = -1, sel_v = -1;

        for (row = 1; row <= vertex_count; row++) {
            if (visited[row] == 1) {
                for (column = 1; column <= vertex_count; column++) {
                    if (visited[column] == 0 && cost_matrix[row][column] < min_cost) {
                        min_cost = cost_matrix[row][column];
                        sel_u = row;
                        sel_v = column;
                    }
                }
            }
        }

        if (sel_u == -1 || sel_v == -1 || min_cost == INF) {
            printf("\nGraph is disconnected. MST cannot be formed for all vertices.\n");
            break;
        }

        visited[sel_v] = 1;
        sum_cost += min_cost;
        count++;
        printf("Edge %d: (%d -> %d) cost = %d\n",
               count, vertex_array[sel_u], vertex_array[sel_v], min_cost);

        cost_matrix[sel_u][sel_v] = cost_matrix[sel_v][sel_u] = INF;
    }

    if (count == edge_count) {
        printf("\nMinimum cost = %d\n", sum_cost);
    } else {
        printf("\nPartial cost = %d (not a complete MST)\n", sum_cost);
    }

    return 0;
}
