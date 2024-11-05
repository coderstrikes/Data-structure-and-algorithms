#include <stdio.h>
void dijkstras(int n, int adj[10][10], int s, int dist[10], int pred[10]) {
    int i, v, count = 1, min, visited[10];
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = adj[s][i];
        if (dist[i] < 999) 
            pred[i] = s;   
        else
            pred[i] = -1; 
    }
    visited[s] = 1;
    dist[s] = 0;
    while (count <= n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;
        for (i = 1; i <= n; i++) {
            if (dist[i] > dist[v] + adj[v][i]) {
                dist[i] = dist[v] + adj[v][i];
                pred[i] = v;
            }
        }
    }
}
void printPath(int s, int j, int pred[]) {
    if (s == j) {
        printf("%d", s);
        return;
    }
    printPath(s, pred[j], pred);
    printf("->%d", j);
}
int main() {
    int i, j, n, s, adj[10][10], dist[10], pred[10];
    printf("Enter the no. of nodes:");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
                adj[i][j] = 999;
        }
    }
    printf("\nEnter the source vertex:");
    scanf("%d", &s);
    dijkstras(n, adj, s, dist, pred);
    printf("\nShortest path from %d is\n", s);
    for (i = 1; i <= n; i++) {
        if (s != i) {
            printf("%d->%d = %d\tPath = ", s, i, dist[i]);
            printPath(s, i, pred);
            printf("\n");
        }
    }
    return 0;
}
