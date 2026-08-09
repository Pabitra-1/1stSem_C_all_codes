
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;

        // Circular connection to itself
        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    // Find last node
    struct Node *last = (*head)->prev;

    // Connect new node
    newNode->next = *head;
    newNode->prev = last;

    // Update old last node
    last->next = newNode;

    // Update head's previous pointer
    (*head)->prev = newNode;
}

// Display forward
void displayForward(struct Node *head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// Display backward
void displayBackward(struct Node *head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Last node
    struct Node *temp = head->prev;

    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);

    printf("(back to last)\n");
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Forward:\n");
    displayForward(head);

    printf("\nBackward:\n");
    displayBackward(head);

    return 0;
}

