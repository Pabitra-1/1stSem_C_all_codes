#include <stdio.h>
#include <string.h>

#define SIZE 10

struct Student {
    int roll;
    char name[50];
    float marks;
    int status;
};

struct Student table[SIZE];

int hash(int roll) {
    return roll % SIZE;
}

void insert() {
    int roll, index, i;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    index = hash(roll);

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 1 &&
            table[pos].roll == roll) {
            printf("Record already exists\n");
            return;
        }

        if (table[pos].status == 0) {
            table[pos].roll = roll;

            printf("Enter name: ");
            scanf(" %49[^\n]", table[pos].name);

            printf("Enter marks: ");
            scanf("%f", &table[pos].marks);

            table[pos].status = 1;

            printf("Student record inserted\n");
            return;
        }
    }

    printf("Hash table is full\n");
}

void search() {
    int roll, index, i;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    index = hash(roll);

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos].status == 0)
            break;

        if (table[pos].status == 1 &&
            table[pos].roll == roll) {
            printf("\nRoll: %d", table[pos].roll);
            printf("\nName: %s", table[pos].name);
            printf("\nMarks: %.2f\n", table[pos].marks);
            return;
        }
    }

    printf("Student not found\n");
}

void display() {
    int i;

    printf("\nRoll\tName\t\tMarks\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i].status == 1) {
            printf("%d\t%-15s\t%.2f\n",
                   table[i].roll,
                   table[i].name,
                   table[i].marks);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert Student");
        printf("\n2.Search Student");
        printf("\n3.Display Records");
        printf("\n4.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                search();
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