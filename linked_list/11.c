
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

// Insert node at the end
void insertAtEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    // Move to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect last node with new node
    temp->next = newNode;
    newNode->prev = temp;
}

// Display from beginning to end
void displayForward(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Display from end to beginning
void displayBackward(struct Node *head) {

    if (head == NULL)
        return;

    struct Node *temp = head;

    // Go to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Move backwards
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Forward:\n");
    displayForward(head);

    printf("Backward:\n");
    displayBackward(head);

    return 0;
}

