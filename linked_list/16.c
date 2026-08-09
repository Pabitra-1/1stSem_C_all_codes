
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Push an element onto the stack
void push(struct Node **top, int data) {

    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = *top;

    *top = newNode;
}

// Pop an element from the stack
int pop(struct Node **top) {

    if (*top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node *temp = *top;
    int data = temp->data;

    *top = (*top)->next;

    free(temp);

    return data;
}

// Return the top element
int peek(struct Node *top) {

    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    return top->data;
}

// Display stack
void display(struct Node *top) {

    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    while (top != NULL) {
        printf("%d\n", top->data);
        top = top->next;
    }
}

int main() {

    struct Node *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);

    printf("Stack:\n");
    display(top);

    printf("\nTop element: %d\n", peek(top));

    printf("\nPopped: %d\n", pop(&top));

    printf("\nStack after pop:\n");
    display(top);

    return 0;
}

