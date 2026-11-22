#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;

    int matrix[10][10];
    int rows, cols, i, j;

    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);

    if (rows < 1 || rows > 10 || cols < 1 || cols > 10) {
        printf("Invalid matrix size!\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0) {
                newNode = malloc(sizeof(struct Node));

                if (newNode == NULL)
                    return 1;

                newNode->row = i;
                newNode->col = j;
                newNode->value = matrix[i][j];
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
        }
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row\tColumn\tValue\n");

    temp = head;

    while (temp != NULL) {
        printf("%d\t%d\t%d\n",
               temp->row,
               temp->col,
               temp->value);

        temp = temp->next;
    }

    return 0;
}