#include <stdio.h>

#define SIZE 11

int table[SIZE];
int status[SIZE] = {0};

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {
    int i, index;

    for (i = 0; i < SIZE; i++) {
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (status[index] == 1 && table[index] == key) {
            printf("Key already exists\n");
            return;
        }

        if (status[index] == 0) {
            table[index] = key;
            status[index] = 1;

            printf("Key inserted at index %d\n", index);
            return;
        }
    }

    printf("Hash table is full\n");
}

void search(int key) {
    int i, index;

    for (i = 0; i < SIZE; i++) {
        index = (hash1(key) + i * hash2(key)) % SIZE;

        if (status[index] == 0)
            break;

        if (status[index] == 1 && table[index] == key) {
            printf("Key found at index %d\n", index);
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
        else
            printf("Empty\n");
    }
}

int main() {
    int choice, key;

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
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
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}