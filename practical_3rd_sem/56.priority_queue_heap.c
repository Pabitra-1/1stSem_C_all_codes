#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void insert(int value) {
    int i, temp;

    if (size == MAX) {
        printf("Priority Queue is full\n");
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

void deleteHighestPriority() {
    int i = 0, largest, temp;

    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;

    while (1) {
        largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

void display() {
    int i;

    printf("Priority Queue: ");
    for (i = 0; i < size; i++)
        printf("%d ", heap[i]);

    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteHighestPriority();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}