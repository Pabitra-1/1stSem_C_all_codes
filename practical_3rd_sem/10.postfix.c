#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char postfix[MAX];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%99s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {

        if (isdigit((unsigned char)postfix[i])) {
            push(postfix[i] - '0');
        }
        else {
            if (top < 1) {
                printf("Invalid expression!\n");
                return 0;
            }

            b = pop();
            a = pop();

            switch (postfix[i]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        printf("Division by zero!\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                case '^':
                    result = 1;

                    if (b < 0) {
                        printf("Negative exponent not supported!\n");
                        return 0;
                    }

                    for (int j = 0; j < b; j++) {
                        result *= a;
                    }
                    break;

                default:
                    printf("Invalid operator!\n");
                    return 0;
            }

            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid expression!\n");
    }
    else {
        printf("Result = %d\n", pop());
    }

    return 0;
}