#include <stdio.h>

int main() {
    int arr[100], n, i, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &value);

    if (pos < 1 || pos > n + 1 || n >= 100) {
        printf("Invalid position or array full!");
        return 0;
    }

    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    printf("Array after insertion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}