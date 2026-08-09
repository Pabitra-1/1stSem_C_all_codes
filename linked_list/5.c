
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

// Delete from head
void deleteAtHead(struct Node **head) {

    if (*head == NULL) {
        return;
    }

    struct Node *temp = *head;

    *head = (*head)->next;

    free(temp);
}

// Delete from tail
void deleteAtTail(struct Node **head) {

    if (*head == NULL) {
        return;
    }

    // Only one node
    if ((*head)->next == NULL) {

        free(*head);
        *head = NULL;

        return;
    }

    struct Node *temp = *head;

    // Find second-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);

    temp->next = NULL;
}

// Delete from specific index
void deleteAtIndex(struct Node **head, int idx) {

    if (*head == NULL) {
        return;
    }

    int size = sizeOfList(*head);

    // Check invalid index
    if (idx < 0 || idx >= size) {
        printf("Invalid index\n");
        return;
    }

    // Delete first node
    if (idx == 0) {
        deleteAtHead(head);
        return;
    }

    // Delete last node
    if (idx == size - 1) {
        deleteAtTail(head);
        return;
    }

    struct Node *temp = *head;

    // Move to node before index
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }

    struct Node *toDelete = temp->next;

    temp->next = toDelete->next;

    free(toDelete);
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("Original list:\n");
    display(head);

    deleteAtHead(&head);

    printf("After deleting head:\n");
    display(head);

    deleteAtTail(&head);

    printf("After deleting tail:\n");
    display(head);

    deleteAtIndex(&head, 1);

    printf("After deleting index 1:\n");
    display(head);

    return 0;
}

