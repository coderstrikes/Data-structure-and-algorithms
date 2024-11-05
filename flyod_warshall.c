#include <stdio.h>
void display(int mat[50][50], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", mat[i][j]);
    }
}
void read(int mat[50][50], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
int main() {
    int adj[50][50], Q[50][50], n, i, j, k;
    printf("\n Enter the number of nodes in the graph : ");
    scanf("%d", &n);
    printf("\n Enter the adjacency matrix : \n");
    read(adj, n);
    printf("\n The adjacency matrix is : ");
    display(adj, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
                Q[i][j] = adj[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (Q[i][j] <= Q[i][k] + Q[k][j])
                    Q[i][j] = Q[i][j];
                else
                    Q[i][j] = Q[i][k] + Q[k][j];
            }
        }
        printf("\n\n");
        display(Q, n);
    }
    return 0;
}
