#include <stdio.h>
void read(int mat[5][5], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf(" %d", &mat[i][j]);
        }
    }
}
void display(int mat[5][5], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int adj[5][5], P[5][5], n, i, j, k;
    printf("\n Enter the number of nodes in the graph : ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix :\n");
    read(adj, n);
    printf("\n The adjacency matrix is : \n");
    display(adj, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 0)
                P[i][j] = 0;
            else
                P[i][j] = 1;
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                P[i][j] = P[i][j] | (P[i][k] & P[k][j]);
        }
    }
    printf("\n The Path Matrix is :\n");
    display(P, n);
    return 0;
}
