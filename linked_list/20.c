
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

// Insert a term into the polynomial
// Combines terms having the same exponent
void insertTerm(struct Node **head, int coeff, int exp) {

    if (coeff == 0)
        return;

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Find the position based on exponent
    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    // Same exponent already exists
    if (temp != NULL && temp->exp == exp) {

        temp->coeff += coeff;

        // Remove node if coefficient becomes zero
        if (temp->coeff == 0) {

            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
        }

        return;
    }

    // Create new node
    struct Node *newNode = createNode(coeff, exp);

    // Insert at beginning
    if (prev == NULL) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        newNode->next = temp;
        prev->next = newNode;
    }
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

// Multiply two polynomials
struct Node* multiplyPolynomial(struct Node *p1, struct Node *p2) {

    struct Node *result = NULL;

    struct Node *i = p1;

    while (i != NULL) {

        struct Node *j = p2;

        while (j != NULL) {

            int coeff = i->coeff * j->coeff;
            int exp = i->exp + j->exp;

            insertTerm(&result, coeff, exp);

            j = j->next;
        }

        i = i->next;
    }

    return result;
}

int main() {

    struct Node *p1 = NULL;
    struct Node *p2 = NULL;
    struct Node *result = NULL;

    /*
        P1 = 2x^2 + 3x + 4
    */

    insertTerm(&p1, 2, 2);
    insertTerm(&p1, 3, 1);
    insertTerm(&p1, 4, 0);

    /*
        P2 = x + 5
    */

    insertTerm(&p2, 1, 1);
    insertTerm(&p2, 5, 0);

    printf("Polynomial 1:\n");
    display(p1);

    printf("\nPolynomial 2:\n");
    display(p2);

    result = multiplyPolynomial(p1, p2);

    printf("\nMultiplication:\n");
    display(result);

    return 0;
}

