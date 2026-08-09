
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

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Concatenate two lists
void concatenate(struct Node *head1, struct Node *head2) {

    // If first list is empty, nothing to connect
    if (head1 == NULL) {
        return;
    }

    struct Node *temp = head1;

    // Find the last node of first list
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect last node of list 1 to first node of list 2
    temp->next = head2;
}

// Display list
void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    // First list
    insertAtEnd(&head1, 10);
    insertAtEnd(&head1, 20);
    insertAtEnd(&head1, 30);

    // Second list
    insertAtEnd(&head2, 40);
    insertAtEnd(&head2, 50);
    insertAtEnd(&head2, 60);

    printf("List 1:\n");
    display(head1);

    printf("List 2:\n");
    display(head2);

    concatenate(head1, head2);

    printf("After concatenation:\n");
    display(head1);

    return 0;
}

