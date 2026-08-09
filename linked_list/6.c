
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

// Find an element
int findElement(struct Node *head, int val) {

    while (head != NULL) {

        if (head->val == val) {
            return 1;
        }

        head = head->next;
    }

    return 0;
}

int main() {

    struct Node *head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    display(head);

    int ele = findElement(head, 2);

    if (ele) {
        printf("Element found\n");
    }
    else {
        printf("Element not found\n");
    }

    return 0;
}

