#include <stdio.h>

#define SIZE 10

struct Employee {
    int id;
    char name[50];
    float salary;
    char department[30];
    int status;
};

struct Employee table[SIZE];

int hash(int id) {
    return id % SIZE;
}

void insert() {
    int id, i, index, pos;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    index = hash(id);

    for (i = 0; i < SIZE; i++) {
        pos = (index + i * i) % SIZE;

        if (table[pos].status == 1 &&
            table[pos].id == id) {
            printf("Employee already exists\n");
            return;
        }

        if (table[pos].status == 0) {
            table[pos].id = id;

            printf("Enter employee name: ");
            scanf(" %49[^\n]", table[pos].name);

            printf("Enter salary: ");
            scanf("%f", &table[pos].salary);

            printf("Enter department: ");
            scanf(" %29[^\n]", table[pos].department);

            table[pos].status = 1;

            printf("Employee inserted successfully\n");
            return;
        }
    }

    printf("No available position\n");
}

void search() {
    int id, i, index, pos;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    index = hash(id);

    for (i = 0; i < SIZE; i++) {
        pos = (index + i * i) % SIZE;

        if (table[pos].status == 0)
            break;

        if (table[pos].status == 1 &&
            table[pos].id == id) {
            printf("\nID: %d", table[pos].id);
            printf("\nName: %s", table[pos].name);
            printf("\nSalary: %.2f", table[pos].salary);
            printf("\nDepartment: %s\n",
                   table[pos].department);
            return;
        }
    }

    printf("Employee not found\n");
}

void display() {
    int i;

    printf("\nID\tName\t\tSalary\tDepartment\n");

    for (i = 0; i < SIZE; i++) {
        if (table[i].status == 1) {
            printf("%d\t%-15s\t%.2f\t%s\n",
                   table[i].id,
                   table[i].name,
                   table[i].salary,
                   table[i].department);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Insert Employee");
        printf("\n2.Search Employee");
        printf("\n3.Display Employees");
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