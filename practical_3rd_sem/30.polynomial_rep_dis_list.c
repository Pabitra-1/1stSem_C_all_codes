#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node *newNode;

    newNode = malloc(sizeof(struct Node));

    if (newNode == NULL)
        return NULL;

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

struct Node* createPolynomial() {
    struct Node *head = NULL;
    struct Node *temp, *newNode;

    int n, i, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coeff, &exp);

        newNode = createNode(coeff, exp);

        if (newNode == NULL)
            return head;

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

    return head;
}

struct Node* addPolynomial(struct Node *p1,
                           struct Node *p2) {

    struct Node *result = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;

    int sum;

    while (p1 != NULL && p2 != NULL) {

        if (p1->exp == p2->exp) {
            sum = p1->coeff + p2->coeff;

            if (sum != 0) {
                newNode = createNode(sum, p1->exp);

                if (newNode == NULL)
                    return result;

                if (result == NULL)
                    result = newNode;
                else
                    temp->next = newNode;

                temp = newNode;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        else if (p1->exp > p2->exp) {
            newNode = createNode(p1->coeff, p1->exp);

            if (newNode == NULL)
                return result;

            if (result == NULL)
                result = newNode;
            else
                temp->next = newNode;

            temp = newNode;
            p1 = p1->next;
        }

        else {
            newNode = createNode(p2->coeff, p2->exp);

            if (newNode == NULL)
                return result;

            if (result == NULL)
                result = newNode;
            else
                temp->next = newNode;

            temp = newNode;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        newNode = createNode(p1->coeff, p1->exp);

        if (newNode == NULL)
            return result;

        if (result == NULL)
            result = newNode;
        else
            temp->next = newNode;

        temp = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        newNode = createNode(p2->coeff, p2->exp);

        if (newNode == NULL)
            return result;

        if (result == NULL)
            result = newNode;
        else
            temp->next = newNode;

        temp = newNode;
        p2 = p2->next;
    }

    return result;
}

void display(struct Node *poly) {
    int first = 1;

    while (poly != NULL) {
        if (!first && poly->coeff > 0)
            printf(" + ");
        else if (!first && poly->coeff < 0)
            printf(" - ");

        if (first && poly->coeff < 0)
            printf("-");

        printf("%d", abs(poly->coeff));

        if (poly->exp != 0)
            printf("x^%d", poly->exp);

        first = 0;
        poly = poly->next;
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

    result = addPolynomial(p1, p2);

    printf("Addition Result: ");
    display(result);

    return 0;
}