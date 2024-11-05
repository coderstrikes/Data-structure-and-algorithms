#include <stdio.h>
int MatrixChainMultiplication(int arr[], int n) {
    int minMul[n][n];
    int j, q;
    for (int i = 1; i < n; i++)
        minMul[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            minMul[i][j] = 99999999;
            for (int k = i; k <= j - 1; k++) {
                q = minMul[i][k] + minMul[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (q < minMul[i][j])
                    minMul[i][j] = q;
            }
        }
    }
    return minMul[1][n - 1];
}
int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter the dimensions of matrices (n+1 integers where nth matrix has dimensions arr[i] x arr[i+1]): ");
    for (int i = 0; i < n+1; i++)
        scanf("%d", &arr[i]);
    printf("Minimum number of multiplications required for the matrices multiplication is %d\n", MatrixChainMultiplication(arr, n + 1));
    return 0;
}
