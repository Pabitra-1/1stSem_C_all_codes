#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;

    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL)
            return 1;

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else {
            temp = head->prev;

            newNode->next = head;
            newNode->prev = temp;

            temp->next = newNode;
            head->prev = newNode;
        }
    }

    printf("\nCircular Doubly Linked List (Forward):\n");

    if (head != NULL) {
        temp = head;

        do {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(Back to Head)\n");

    printf("\nCircular Doubly Linked List (Backward):\n");

    if (head != NULL) {
        temp = head->prev;

        do {
            printf("%d <-> ", temp->data);
            temp = temp->prev;
        } while (temp != head->prev);
    }

    printf("(Back to Tail)\n");

    return 0;
}