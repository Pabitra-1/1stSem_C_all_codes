
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Create node
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

// Print in reverse using recursion
void reversePrint(struct Node *head) {

    // Base case
    if (head == NULL) {
        return;
    }

    // Go to the end first
    reversePrint(head->next);

    // Print while returning
    printf("%d -> ", head->data);
}

// Display normally
void display(struct Node *head) {

    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Original list:\n");
    display(head);

    printf("Reverse printing:\n");
    reversePrint(head);
    printf("NULL\n");

    return 0;
}

