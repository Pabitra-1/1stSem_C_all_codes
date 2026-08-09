
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row;
    int col;
    int value;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int row, int col, int value) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

// Insert a non-zero element
void insert(struct Node **head, int row, int col, int value) {

    if (value == 0)
        return;

    struct Node *newNode = createNode(row, col, value);

    // Empty list
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display sparse matrix as a list
void displayList(struct Node *head) {

    printf("Row\tColumn\tValue\n");

    while (head != NULL) {
        printf("%d\t%d\t%d\n",
               head->row,
               head->col,
               head->value);

        head = head->next;
    }
}

// Display the original matrix
void displayMatrix(struct Node *head, int rows, int cols) {

    struct Node *temp = head;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (temp != NULL &&
                temp->row == i &&
                temp->col == j) {

                printf("%d ", temp->value);
                temp = temp->next;
            }
            else {
                printf("0 ");
            }
        }

        printf("\n");
    }
}

int main() {

    struct Node *head = NULL;

    int rows = 3;
    int cols = 4;

   

    insert(&head, 0, 2, 3);
    insert(&head, 1, 1, 4);
    insert(&head, 2, 0, 5);
    insert(&head, 2, 3, 7);

    printf("Sparse Matrix Representation:\n\n");

    displayList(head);

    printf("\nOriginal Matrix:\n\n");

    displayMatrix(head, rows, cols);

    return 0;
}

