#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[100][100];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[100], visited[100];

    for(int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for(int count = 1; count <= n; count++) {
        int min = INT_MAX, u;

        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0 && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        total += key[u];

        for(int v = 1; v <= n; v++) {
            if(graph[u][v] != INT_MAX && visited[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", total);

    return 0;
}