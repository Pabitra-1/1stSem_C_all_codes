#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertEnd(int value) {
    struct Node *newNode, *temp;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

void insertPosition(int value, int pos) {
    struct Node *newNode, *temp;
    int i;

    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertBeginning(value);
        return;
    }

    if (head == NULL) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != pos - 1) {
        printf("Invalid position!\n");
        return;
    }

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteBeginning() {
    struct Node *temp, *last;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct Node *temp, *prev;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == head) {
        deleteBeginning();
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void deletePosition(int pos) {
    struct Node *temp, *prev;
    int i;

    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos) {
        printf("Invalid position!\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted: %d\n", temp->data);
    free(temp);
}

void display() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to Head)\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n1. Insert Beginning");
        printf("\n2. Insert End");
        printf("\n3. Insert Position");
        printf("\n4. Delete Beginning");
        printf("\n5. Delete End");
        printf("\n6. Delete Position");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &pos);
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}