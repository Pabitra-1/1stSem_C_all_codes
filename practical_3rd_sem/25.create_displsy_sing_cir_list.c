#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
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
        }
        else {
            temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Circular Linked List:\n");

    if (head != NULL) {
        temp = head;

        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("(Back to Head)\n");

    return 0;
}