#include <stdio.h>

void traverse(int arr[], int n) {
    int i;

    printf("Array elements are: ");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    traverse(arr, n);

    return 0;
}