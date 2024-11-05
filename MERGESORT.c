#include <stdio.h>

int i, j, k, m, n, a[50], b[50], c[50], p, q, r;

void merge(int a[], int b[], int m, int n) {
  int i = 0, j = 0, k = 0;
  while (i < m && j < n) {
    if (a[i] < b[j]) {
      c[k++] = a[i++];
    } else {
      c[k++] = b[j++];
    }
  }
  for (; i < m; i++) {
    c[k++] = a[i];
  }
  for (; j < n; j++) {
    c[k++] = b[j];
  }
}

void merge_sort(int a[], int p, int r) {
  if (p < r) { // Fix: Change from p > r to p < r
    q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a + p, a + q + 1, q - p + 1, r - q); // Fix: Pass correct arguments to merge
    for (i = p; i <= r; i++) {
      a[i] = c[i - p];
    }
  }
}

int main() {
  printf("Enter the no. of elements:");
  scanf("%d", &n);
  printf("Enter the array elements:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n - 1);
  printf("The sorted array is:");
  for (i = 0; i < n; i++) {
    printf(" %d", a[i]); // Add a space before %d to separate elements
  }
  return 0;
}
