
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    // If list is empty
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node *temp = *head;

    // Find the last node
    while (temp->next != *head) {
        temp = temp->next;
    }

    // Connect last node to new node
    temp->next = newNode;

    // Connect new node back to head
    newNode->next = *head;
}

// Display circular list
void display(struct Node *head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    display(head);

    return 0;
}

