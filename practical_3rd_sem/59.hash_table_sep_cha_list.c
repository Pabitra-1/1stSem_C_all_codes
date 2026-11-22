#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *table[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct Node *temp = table[index];
    struct Node *newNode;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key already exists\n");
            return;
        }
        temp = temp->next;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = key;
    newNode->next = table[index];
    table[index] = newNode;

    printf("Inserted successfully\n");
}

void search(int key) {
    int index = hash(key);
    struct Node *temp = table[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key found\n");
            return;
        }

        temp = temp->next;
    }

    printf("Key not found\n");
}

void deleteKey(int key) {
    int index = hash(key);
    struct Node *temp = table[index];
    struct Node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Key deleted successfully\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Key not found\n");
}

void display() {
    int i;
    struct Node *temp;

    for (i = 0; i < SIZE; i++) {
        printf("\n%d: ", i);

        temp = table[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL");
    }

    printf("\n");
}

int main() {
    int choice, key;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}