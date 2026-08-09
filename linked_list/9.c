
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

// Delete duplicates
void deleteDuplicates(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {

        struct Node *prev = current;
        struct Node *temp = current->next;

        while (temp != NULL) {

            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
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

    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 10);

    printf("Before deleting duplicates:\n");
    display(head);

    deleteDuplicates(head);

    printf("After deleting duplicates:\n");
    display(head);

    return 0;
}

