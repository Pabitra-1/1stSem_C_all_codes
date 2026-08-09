
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

// Initialize queue
void initialize(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

// Enqueue
void enqueue(struct Queue *q, int data) {

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    // If queue is empty
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    // Add node at rear
    q->rear->next = newNode;
    q->rear = newNode;
}



// Peek
int peek(struct Queue *q) {

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->front->data;
}

// Display
void display(struct Queue *q) {

    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = q->front;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Queue q;

    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Queue:\n");
    display(&q);

    printf("\nFront element: %d\n", peek(&q));

    printf("\nDequeued: %d\n", dequeue(&q));

    printf("\nQueue after dequeue:\n");
    display(&q);

    return 0;
}

