#include <stdio.h>
#define MAX 5
void breadth_first_search(int adj[][MAX],int visited[],int start){
	int queue[MAX],i,rear=-1,front=-1;
	queue[++rear] = start;
	visited[start] = 1;
	while(rear != front){
		start = queue[++front];
		printf("%c -> ",start + 65);
		for(i = 0; i < MAX; i++){
			if(adj[start][i] == 1 && visited[i] == 0){
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}
int main(){
	int visited[MAX] = {0};
	int adj[MAX][MAX], i, j;
	printf("\n Enter the adjacency matrix: ");
	for(i = 0; i < MAX; i++){
		for(j = 0; j < MAX; j++)
			scanf("%d", &adj[i][j]);
		}
	printf("BFS Traversal:");
	breadth_first_search(adj,visited,0);
	return 0;
}
