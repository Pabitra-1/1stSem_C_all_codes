
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Deque {
    struct Node *front;
    struct Node *rear;
};

// Initialize deque
void initialize(struct Deque *dq) {
    dq->front = NULL;
    dq->rear = NULL;
}

// Create a new node
struct Node* createNode(int data) {

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at front
void insertFront(struct Deque *dq, int data) {

    struct Node *newNode = createNode(data);

    // Empty deque
    if (dq->front == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
        return;
    }

    newNode->next = dq->front;
    dq->front->prev = newNode;

    dq->front = newNode;
}

// Insert at rear
void insertRear(struct Deque *dq, int data) {

    struct Node *newNode = createNode(data);

    // Empty deque
    if (dq->rear == NULL) {
        dq->front = newNode;
        dq->rear = newNode;
        return;
    }

    newNode->prev = dq->rear;
    dq->rear->next = newNode;

    dq->rear = newNode;
}

// Delete from front
int deleteFront(struct Deque *dq) {

    if (dq->front == NULL) {
        printf("Deque is empty\n");
        return -1;
    }

    struct Node *temp = dq->front;
    int data = temp->data;

    // Only one node
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else {
        dq->front = dq->front->next;
        dq->front->prev = NULL;
    }

    free(temp);

    return data;
}

// Delete from rear
int deleteRear(struct Deque *dq) {

    if (dq->rear == NULL) {
        printf("Deque is empty\n");
        return -1;
    }

    struct Node *temp = dq->rear;
    int data = temp->data;

    // Only one node
    if (dq->front == dq->rear) {
        dq->front = NULL;
        dq->rear = NULL;
    }
    else {
        dq->rear = dq->rear->prev;
        dq->rear->next = NULL;
    }

    free(temp);

    return data;
}

// Display deque
void display(struct Deque *dq) {

    if (dq->front == NULL) {
        printf("Deque is empty\n");
        return;
    }

    struct Node *temp = dq->front;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Deque dq;

    initialize(&dq);

    insertRear(&dq, 20);
    insertRear(&dq, 30);
    insertFront(&dq, 10);
    insertRear(&dq, 40);

    printf("Deque:\n");
    display(&dq);

    printf("\nDeleted from front: %d\n", deleteFront(&dq));
    display(&dq);

    printf("\nDeleted from rear: %d\n", deleteRear(&dq));
    display(&dq);

    return 0;
}

