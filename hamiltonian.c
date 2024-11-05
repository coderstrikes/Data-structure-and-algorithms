#include <stdio.h>
int graph[50][50];
int path[50];
int NODE;
void displayCycle() {
    printf("Cycle Found: ");
    for (int i = 0; i < NODE; i++)
        printf("%d ", path[i]+1);

    printf("%d\n", path[0]+1);
}
int isValid(int v, int k) {
    if (graph[path[k - 1]][v] == 0)
        return 0;
    for (int i = 0; i < k; i++)
        if (path[i] == v)
            return 0;
    return 1;
}
int cycleFound(int k) {
    if (k == NODE) {

        if (graph[path[k - 1]][path[0]] == 1)
            return 1;
        else
            return 0;
    }
    for (int v = 1; v < NODE; v++) {
        if (isValid(v, k)) {
            path[k] = v;
            if (cycleFound(k + 1) == 1)
                return 1;
            path[k] = -1;
        }
    }
    return 0;
}
int hamiltonianCycle() {
    for (int i = 0; i < NODE; i++)
        path[i] = -1;
    path[0] = 0;
    if (cycleFound(1) == 0) {
        printf("Solution does not exist\n");
        return 0;
    }
    displayCycle();
    return 1;
}

int main() {
	printf("Enter the number of nodes:");
	scanf("%d",&NODE);
    printf("Enter the adjacency matrix (%d x %d):\n", NODE, NODE);
    for (int i = 0; i < NODE; i++) {
        for (int j = 0; j < NODE; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    hamiltonianCycle();
    return 0;
}
