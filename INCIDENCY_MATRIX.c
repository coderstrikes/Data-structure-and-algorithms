#include <stdio.h>
#include <stdlib.h>
void createIncidenceMatrix(int Inc[][10], int no_of_nodes, int no_of_edges) {
    int val;
    for (int i = 0; i < no_of_nodes; i++) {
        printf("\nEnter the edges incident on node %d (0-based indices): ", i);
        for (int j = 0; j < no_of_edges; j++) {
            Inc[i][j] = 0;  // Initialize all values to 0
        }
        printf("\nEnter the number of edges incident on node %d: ", i);
        scanf("%d", &val);
        printf("\nEnter the edges incident on node %d (0-based indices): ", i);
        for (int j = 0; j < val; j++) {
            int edge;
            scanf("%d", &edge);
            Inc[i][edge] = 1;  // Set the corresponding entry to 1 for incident edges
        }
    }
}
void displayIncidenceMatrix(int Inc[][10], int no_of_nodes, int no_of_edges) {
    printf("\nThe incidence matrix is:\n");
    for (int i = 0; i < no_of_nodes; i++) {
        for (int j = 0; j < no_of_edges; j++) {
            printf("%d\t", Inc[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int Inc[10][10];
    int no_of_nodes, no_of_edges;
    printf("\nEnter the number of nodes in G: ");
    scanf("%d", &no_of_nodes);
    printf("\nEnter the number of edges in G: ");
    scanf("%d", &no_of_edges);
    createIncidenceMatrix(Inc, no_of_nodes, no_of_edges);
    printf("\nThe incidence matrix is: ");
    displayIncidenceMatrix(Inc, no_of_nodes, no_of_edges);
    return 0;
}
