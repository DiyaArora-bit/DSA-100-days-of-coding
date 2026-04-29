#include <stdio.h>

int visited[1000];
int adj[1000][1000];

void dfs(int node, int n) {
    visited[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] == 1 && visited[i] == 0) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1, n);

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            printf("NOT CONNECTED\n");
            return 0;
        }
    }

    printf("CONNECTED\n");

    return 0;
}