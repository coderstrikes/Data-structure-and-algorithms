#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int random_partition(int a[50], int lb, int ub) {
    srand(time(NULL)); // Seed for random number generator
    int random_index = lb + rand() % (ub - lb + 1); // Generate a random index within the range
    swap(&a[random_index], &a[lb]); // Swap the randomly chosen pivot element with the first element
    int pivot = a[lb];
    int left = lb;
    int right = ub;
    while (left < right) {
        while (pivot < a[right])
            right--;
        while (pivot > a[left])
            left++;
        if (left < right) {
            swap(&a[left], &a[right]);
        }
    }
    swap(&a[lb], &a[right]); // Swap the pivot element with the element at the right index
    return right; // Return the partition index
}
void quicksort(int a[50], int lb, int ub) {
    if (lb < ub) {
        int pivot = random_partition(a, lb, ub);
        quicksort(a, lb, pivot - 1);
        quicksort(a, pivot + 1, ub);
    }
}
int main() {
    int a[50], i, n;
    printf("Enter the number of items:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("The array is:");
    for (i = 0; i < n; i++)
        printf(" %d ", a[i]);
    quicksort(a, 0, n - 1);
    printf("\nThe sorted array is:");
    for (i = 0; i < n; i++)
        printf(" %d", a[i]);
    return 0;
}
