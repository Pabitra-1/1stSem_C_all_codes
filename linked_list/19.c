
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

// Create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

// Insert a term at the end
void insertTerm(struct Node **head, int coeff, int exp) {

    if (coeff == 0)
        return;

    struct Node *newNode = createNode(coeff, exp);

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

// Display polynomial
void display(struct Node *head) {

    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {

        printf("%dx^%d", head->coeff, head->exp);

        if (head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

// Add two polynomials
struct Node* addPolynomial(struct Node *p1, struct Node *p2) {

    struct Node *result = NULL;

    while (p1 != NULL && p2 != NULL) {

        // Same exponent
        if (p1->exp == p2->exp) {

            int sum = p1->coeff + p2->coeff;

            if (sum != 0)
                insertTerm(&result, sum, p1->exp);

            p1 = p1->next;
            p2 = p2->next;
        }

        // p1 has greater exponent
        else if (p1->exp > p2->exp) {

            insertTerm(&result, p1->coeff, p1->exp);

            p1 = p1->next;
        }

        // p2 has greater exponent
        else {

            insertTerm(&result, p2->coeff, p2->exp);

            p2 = p2->next;
        }
    }

    // Remaining terms of p1
    while (p1 != NULL) {

        insertTerm(&result, p1->coeff, p1->exp);

        p1 = p1->next;
    }

    // Remaining terms of p2
    while (p2 != NULL) {

        insertTerm(&result, p2->coeff, p2->exp);

        p2 = p2->next;
    }

    return result;
}

int main() {

    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;

    /*
        P1 = 5x^3 + 4x^2 + 2x + 7
    */

    insertTerm(&p1, 5, 3);
    insertTerm(&p1, 4, 2);
    insertTerm(&p1, 2, 1);
    insertTerm(&p1, 7, 0);

    /*
        P2 = 3x^3 + 6x^2 + 5
    */

    insertTerm(&p2, 3, 3);
    insertTerm(&p2, 6, 2);
    insertTerm(&p2, 5, 0);

    printf("Polynomial 1:\n");
    display(p1);

    printf("\nPolynomial 2:\n");
    display(p2);

    result = addPolynomial(p1, p2);

    printf("\nAddition:\n");
    display(result);

    return 0;
}

