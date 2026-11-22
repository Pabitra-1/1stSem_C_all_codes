#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createTree() {
    int value;
    struct Node *newNode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    printf("Enter left child of %d\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d\n", value);
    newNode->right = createTree();

    return newNode;
}

/* Non-recursive Inorder */
void inorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;

    while (root != NULL || top != -1) {
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

        root = stack[top--];

        printf("%d ", root->data);

        root = root->right;
    }
}

/* Non-recursive Preorder */
void preorder(struct Node *root) {
    struct Node *stack[100];
    int top = -1;

    if (root == NULL)
        return;

    stack[++top] = root;

    while (top != -1) {
        root = stack[top--];

        printf("%d ", root->data);

        if (root->right != NULL)
            stack[++top] = root->right;

        if (root->left != NULL)
            stack[++top] = root->left;
    }
}

/* Non-recursive Postorder */
void postorder(struct Node *root) {
    struct Node *s1[100], *s2[100];
    int top1 = -1, top2 = -1;

    if (root == NULL)
        return;

    s1[++top1] = root;

    while (top1 != -1) {
        root = s1[top1--];

        s2[++top2] = root;

        if (root->left != NULL)
            s1[++top1] = root->left;

        if (root->right != NULL)
            s1[++top1] = root->right;
    }

    while (top2 != -1)
        printf("%d ", s2[top2--]->data);
}

int main() {
    struct Node *root;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}