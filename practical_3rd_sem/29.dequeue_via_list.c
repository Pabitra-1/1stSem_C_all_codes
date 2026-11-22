#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insertFront() {
    struct Node *newNode;
    int value;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        front->prev = newNode;
        front = newNode;
    }
}

void insertRear() {
    struct Node *newNode;
    int value;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void deleteFront() {
    struct Node *temp;

    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    temp = front;

    printf("Deleted element: %d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    else {
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear() {
    struct Node *temp;

    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    temp = rear;

    printf("Deleted element: %d\n", temp->data);

    rear = rear->prev;

    if (rear == NULL) {
        front = NULL;
    }
    else {
        rear->next = NULL;
    }

    free(temp);
}

void display() {
    struct Node *temp = front;

    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }

    printf("Deque elements: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}