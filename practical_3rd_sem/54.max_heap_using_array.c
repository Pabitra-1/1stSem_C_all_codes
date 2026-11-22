#include <stdio.h>

#define MAX 100

int heap[MAX];
int n = 0;

void insert(int value) {
    int i, temp;

    if (n == MAX) {
        printf("Heap is full\n");
        return;
    }

    i = n++;
    heap[i] = value;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void display() {
    int i;

    printf("Max Heap: ");
    for (i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int i, count, value;

    printf("Enter number of elements: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++) {
        printf("Enter element: ");
        scanf("%d", &value);
        insert(value);
    }

    display();

    return 0;
}