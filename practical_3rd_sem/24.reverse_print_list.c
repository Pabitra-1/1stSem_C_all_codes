#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void reverseDisplay(struct Node *head) {
    if (head == NULL)
        return;

    reverseDisplay(head->next);

    printf("%d ", head->data);
}

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

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }
    }

    printf("Reverse order: ");

    reverseDisplay(head);

    printf("\n");

    return 0;
}