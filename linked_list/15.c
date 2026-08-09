
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

/* Create a new node */
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* Display circular list */
void display(struct Node *head) {

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}


//    1. INSERT AT END


void insertAtEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    /* Empty list */
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    /* Find last node */
    struct Node *temp = *head;

    while (temp->next != *head) {
        temp = temp->next;
    }

    /* Connect new node */
    temp->next = newNode;
    newNode->next = *head;
}



//    2. INSERT AT SPECIFIC INDEX


void insertAtIndex(struct Node **head, int data, int index) {

    /* Insert at beginning */
    if (index == 0) {

        struct Node *newNode = createNode(data);

        /* Empty list */
        if (*head == NULL) {
            *head = newNode;
            newNode->next = *head;
            return;
        }

        /* Find last node */
        struct Node *last = *head;

        while (last->next != *head) {
            last = last->next;
        }

        newNode->next = *head;
        last->next = newNode;
        *head = newNode;

        return;
    }

    if (*head == NULL) {
        printf("Invalid index\n");
        return;
    }

    struct Node *temp = *head;

    /* Move to node before index */
    for (int i = 0; i < index - 1; i++) {

        temp = temp->next;

        if (temp == *head) {
            printf("Invalid index\n");
            return;
        }
    }

    struct Node *newNode = createNode(data);

    newNode->next = temp->next;
    temp->next = newNode;
}


//    3. INSERT AT BEGINNING


void insertAtBeginning(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    /* Empty list */
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    /* Find last node */
    struct Node *last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    newNode->next = *head;
    last->next = newNode;

    *head = newNode;
}



//    4. DELETE FROM END


void deleteAtEnd(struct Node **head) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    /* Find second-last node */
    while (temp->next->next != *head) {
        temp = temp->next;
    }

    struct Node *last = temp->next;

    temp->next = *head;

    free(last);
}



//    5. DELETE FROM SPECIFIC INDEX


void deleteAtIndex(struct Node **head, int index) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Delete first node */
    if (index == 0) {

        /* Only one node */
        if ((*head)->next == *head) {
            free(*head);
            *head = NULL;
            return;
        }

        /* Find last node */
        struct Node *last = *head;

        while (last->next != *head) {
            last = last->next;
        }

        struct Node *temp = *head;

        *head = (*head)->next;

        last->next = *head;

        free(temp);

        return;
    }

    struct Node *temp = *head;

    /* Move to node before index */
    for (int i = 0; i < index - 1; i++) {

        temp = temp->next;

        if (temp == *head) {
            printf("Invalid index\n");
            return;
        }
    }

    /* Check if index exists */
    if (temp->next == *head) {
        printf("Invalid index\n");
        return;
    }

    struct Node *deleteNode = temp->next;

    temp->next = deleteNode->next;

    free(deleteNode);
}



//    6. DELETE FROM BEGINNING


void deleteAtBeginning(struct Node **head) {

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    /* Only one node */
    if ((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }

    /* Find last node */
    struct Node *last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    struct Node *temp = *head;

    *head = (*head)->next;

    last->next = *head;

    free(temp);
}



int main() {

    struct Node *head = NULL;

    /* Insert at end */
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Initial list:\n");
    display(head);


    /* Insert at beginning */
    insertAtBeginning(&head, 5);

    printf("\nAfter inserting 5 at beginning:\n");
    display(head);


    /* Insert at index */
    insertAtIndex(&head, 25, 3);

    printf("\nAfter inserting 25 at index 3:\n");
    display(head);


    /* Delete from end */
    deleteAtEnd(&head);

    printf("\nAfter deleting from end:\n");
    display(head);


    /* Delete from index */
    deleteAtIndex(&head, 2);

    printf("\nAfter deleting index 2:\n");
    display(head);


    /* Delete from beginning */
    deleteAtBeginning(&head);

    printf("\nAfter deleting from beginning:\n");
    display(head);


    return 0;
}

