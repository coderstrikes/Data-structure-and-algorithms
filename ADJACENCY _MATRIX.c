#include <stdio.h>
#include <stdlib.h>
void createGraph(int Adj[][10], int no_of_nodes) {
    int val;
    for (int i = 0; i < no_of_nodes; i++) {
        printf("\nEnter the number of neighbors of %d: ", i);
        scanf("%d", &val);
        printf("\nEnter the neighbors of %d (0-based indices): ", i);
        for (int j = 0; j < no_of_nodes; j++) {
            Adj[i][j] = 0;
        }
        for (int j = 0; j < val; j++) {
            int neighbor;
            scanf("%d", &neighbor);
            Adj[i][neighbor] = 1;
        }
    }
}
void displayGraph(int Adj[][10], int no_of_nodes) {
    printf("\nThe adjacency matrix is:\n");
    printf("\t");
    for (int i = 0; i < no_of_nodes; i++) {
        printf("v%d\t", i + 1);
    }
    printf("\n");
    for (int i = 0; i < no_of_nodes; i++) {
        printf("v%d\t", i + 1);
        for (int j = 0; j < no_of_nodes; j++) {
            printf("%d\t", Adj[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int Adj[10][10];
    int no_of_nodes;
    printf("\nEnter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);
    createGraph(Adj, no_of_nodes);
    printf("\nThe graph is: ");
    displayGraph(Adj, no_of_nodes);  
    return 0;
}
