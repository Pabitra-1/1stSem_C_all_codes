
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

// 1. Insert at beginning
void insertAtBeginning(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Connect new node with current head
    newNode->next = *head;
    (*head)->prev = newNode;

    // Make new node the head
    *head = newNode;
}

// 2. Insert at end
void insertAtEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    // Move to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect last node and new node
    temp->next = newNode;
    newNode->prev = temp;
}

// 3. Insert at any index
void insertAtIndex(struct Node **head, int data, int index) {

    // Insert at beginning
    if (index == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node *temp = *head;

    // Move to node before the required index
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // Index is invalid
    if (temp == NULL) {
        printf("Invalid index\n");
        return;
    }

    struct Node *newNode = createNode(data);

    // Connect new node with next node
    newNode->next = temp->next;
    newNode->prev = temp;

    // If new node is not inserted at the end
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    // Connect previous node with new node
    temp->next = newNode;
}

// Display the list
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    // Insert at beginning
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    // Insert at end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // Insert at index
    insertAtIndex(&head, 30, 2);

    display(head);

    return 0;
}

