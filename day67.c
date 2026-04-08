#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** adj, int* size, int* visited, int* stack, int* top) {
    visited[node] = 1;

    for (int i = 0; i < size[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, adj, size, visited, stack, top);
        }
    }

    stack[(*top)++] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* size = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][size[u]++] = v;
    }

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, size, visited, stack, &top);
        }
    }

    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}