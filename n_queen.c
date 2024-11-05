#include<stdio.h>
#include<stdlib.h>
int *t; 
int n;  
int s = 0; 
void display() {
    int i, j;
    char **chess = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        chess[i] = (char *)malloc(n * sizeof(char));
        for (j = 0; j < n; j++) {
            chess[i][j] = '.';
        }
    }
    for (i = 0; i < n; i++) {
        chess[i][t[i]] = 'Q';
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", chess[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        free(chess[i]);
    }
    free(chess);
}
int place(int i) {
    int j = 0;
    while (j < i) {
        if (t[i] == t[j] || abs(t[i] - t[j]) == abs(i - j))
            return 0; 
        j++;
    }
    return 1; 
}
void nQueens(int i) {
    if (i == n) {
        printf("\n The %d solution\n", s += 1);
        display();
    } else {
        for (t[i] = 0; t[i] < n; t[i]++) {
            if (place(i))
                nQueens(i + 1);
        }
    }
}
int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    t = (int *)malloc(n * sizeof(int)); 
    nQueens(0);
    free(t);
    return 0;
}
