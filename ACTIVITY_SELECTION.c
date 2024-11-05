#include <stdio.h>
#include <stdlib.h>
struct Activity {
    int start;
    int finish;
};
int compare(const void *a, const void *b) {
    struct Activity *x = (struct Activity *)a;
    struct Activity *y = (struct Activity *)b;
    return x->finish - y->finish;
}
void activitySelection(struct Activity arr[], int n) {
    qsort(arr, n, sizeof(struct Activity), compare);
    int i = 0;
    printf("The following activities are selected:\n");
    printf("(%d, %d) ", arr[i].start, arr[i].finish);
    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            printf("(%d, %d) ", arr[j].start, arr[j].finish);
            i = j;
        }
    }
}
int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct Activity arr[n];
    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &arr[i].start, &arr[i].finish);
    }
    activitySelection(arr, n);
    return 0;
}
