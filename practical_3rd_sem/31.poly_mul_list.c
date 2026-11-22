#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int c, int e) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return NULL;

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    return newNode;
}

void insertTerm(struct Node **head, int coeff, int exp) {
    struct Node *temp = *head;
    struct Node *prev = NULL;
    struct Node *newNode;

    if (coeff == 0)
        return;

    while (temp != NULL && temp->exp > exp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp) {
        temp->coeff += coeff;

        if (temp->coeff == 0) {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
        }

        return;
    }

    newNode = createNode(coeff, exp);

    if (newNode == NULL)
        return;

    newNode->next = temp;

    if (prev == NULL)
        *head = newNode;
    else
        prev->next = newNode;
}

struct Node* createPolynomial() {
    struct Node *head = NULL;
    int n, c, e, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &c, &e);

        if (e < 0) {
            printf("Negative exponent not supported!\n");
            i--;
            continue;
        }

        insertTerm(&head, c, e);
    }

    return head;
}

struct Node* multiply(struct Node *p1, struct Node *p2) {
    struct Node *result = NULL;
    struct Node *a, *b;

    for (a = p1; a != NULL; a = a->next) {
        for (b = p2; b != NULL; b = b->next) {

            insertTerm(&result,
                       a->coeff * b->coeff,
                       a->exp + b->exp);
        }
    }

    return result;
}

void display(struct Node *head) {
    int first = 1;

    while (head != NULL) {
        if (!first && head->coeff > 0)
            printf(" + ");
        else if (!first && head->coeff < 0)
            printf(" - ");

        if (first && head->coeff < 0)
            printf("-");

        printf("%d", abs(head->coeff));

        if (head->exp != 0)
            printf("x^%d", head->exp);

        first = 0;
        head = head->next;
    }

    if (first)
        printf("0");

    printf("\n");
}

int main() {
    struct Node *p1, *p2, *result;

    printf("Enter first polynomial:\n");
    p1 = createPolynomial();

    printf("\nEnter second polynomial:\n");
    p2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    result = multiply(p1, p2);

    printf("Multiplication Result: ");
    display(result);

    return 0;
}