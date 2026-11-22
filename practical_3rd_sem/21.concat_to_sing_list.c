#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int i;

    for (i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL)
            return head;

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

    return head;
}

struct Node* concatenate(struct Node *head1,
                         struct Node *head2) {

    struct Node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {
    struct Node *head1, *head2;

    int n;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n);
    head1 = createList(n);

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n);
    head2 = createList(n);

    head1 = concatenate(head1, head2);

    printf("Concatenated List:\n");
    display(head1);

    return 0;
}