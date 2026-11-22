#include <stdio.h>

#define SIZE 10

int table[SIZE];
int status[SIZE] = {0};

/* status: 0 = Empty, 1 = Occupied, 2 = Deleted */

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i, firstDeleted = -1;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 1 && table[pos] == key) {
            printf("Key already exists\n");
            return;
        }

        if (status[pos] == 2 && firstDeleted == -1)
            firstDeleted = pos;

        if (status[pos] == 0) {
            if (firstDeleted != -1)
                pos = firstDeleted;

            table[pos] = key;
            status[pos] = 1;
            printf("Inserted successfully\n");
            return;
        }
    }

    if (firstDeleted != -1) {
        table[firstDeleted] = key;
        status[firstDeleted] = 1;
        printf("Inserted successfully\n");
    } else {
        printf("Hash table is full\n");
    }
}

void search(int key) {
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0)
            break;

        if (status[pos] == 1 && table[pos] == key) {
            printf("Key found at index %d\n", pos);
            return;
        }
    }

    printf("Key not found\n");
}

void deleteKey(int key) {
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0)
            break;

        if (status[pos] == 1 && table[pos] == key) {
            status[pos] = 2;
            printf("Key deleted successfully\n");
            return;
        }
    }

    printf("Key not found\n");
}

void display() {
    int i;

    printf("\nIndex\tValue\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d\t", i);

        if (status[i] == 1)
            printf("%d\n", table[i]);
        else if (status[i] == 2)
            printf("Deleted\n");
        else
            printf("Empty\n");
    }
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