#include <stdio.h>

#define SIZE 100

struct Element {
    int key;
    int frequency;
    int status;
};

struct Element table[SIZE];

int hash(int key) {
    int index = key % SIZE;

    if (index < 0)
        index += SIZE;

    return index;
}

void insert(int key) {
    int index = hash(key);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 1 &&
            table[pos].key == key) {
            table[pos].frequency++;
            return;
        }

        if (table[pos].status == 0) {
            table[pos].key = key;
            table[pos].frequency = 1;
            table[pos].status = 1;
            return;
        }
    }

    printf("Hash table is full\n");
}

void display() {
    int i;

    printf("\nNumber\tFrequency\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i].status == 1) {
            printf("%d\t%d\n",
                   table[i].key,
                   table[i].frequency);
        }
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        insert(arr[i]);
    }

    display();

    return 0;
}