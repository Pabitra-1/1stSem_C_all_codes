#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    struct Node *current, *runner, *prev;

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

    current = head;

    while (current != NULL) {

        prev = current;
        runner = current->next;

        while (runner != NULL) {

            if (current->data == runner->data) {

                prev->next = runner->next;

                free(runner);

                runner = prev->next;
            }
            else {
                prev = runner;
                runner = runner->next;
            }
        }

        current = current->next;
    }

    printf("Linked List after removing duplicates:\n");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}