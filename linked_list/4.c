
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int data) {

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->val = data;
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

// Display
void display(struct Node *head) {

    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }

    printf("NULL\n");
}

// Size of list
int sizeOfList(struct Node *head) {

    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

// Insert at head
void insertAtHead(struct Node **head, int val) {

    struct Node *newNode = createNode(val);

    newNode->next = *head;
    *head = newNode;
}

// Insert at tail
void insertAtTail(struct Node **head, int val) {

    struct Node *newNode = createNode(val);

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

// Insert at index
void insertAtIndex(struct Node **head, int val, int idx) {

    int size = sizeOfList(*head);

    // Invalid index
    if (idx < 0 || idx > size) {
        printf("Invalid index\n");
        return;
    }

    // Insert at beginning
    if (idx == 0) {
        insertAtHead(head, val);
        return;
    }

    // Insert at end
    if (idx == size) {
        insertAtTail(head, val);
        return;
    }

    struct Node *newNode = createNode(val);

    struct Node *temp = *head;

    // Move to node before index
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    display(head);

    insertAtHead(&head, 0);
    display(head);

    insertAtTail(&head, 5);
    display(head);

    insertAtIndex(&head, 10, 3);
    display(head);

    return 0;
}

