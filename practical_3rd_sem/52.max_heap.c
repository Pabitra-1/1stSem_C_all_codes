#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value) {
    int i, temp;

    if (size == MAX) {
        printf("Heap is full\n");
        return;
    }

    i = size++;
    heap[i] = value;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;

        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        heapify(largest);
    }
}

void deleteRoot() {
    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapify(0);
}

void display() {
    int i;

    if (size == 0) {
        printf("Heap is empty\n");
        return;
    }

    printf("Heap: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Delete Root\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                deleteRoot();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}