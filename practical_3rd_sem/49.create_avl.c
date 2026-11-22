#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *root) {
    if (root == NULL)
        return 0;

    return root->height;
}

struct Node* createNode(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;

    return newNode;
}

int getBalance(struct Node *root) {
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

/* Right Rotation - LL Case */
struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left),
                        height(y->right));

    x->height = 1 + max(height(x->left),
                        height(x->right));

    return x;
}

/* Left Rotation - RR Case */
struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left),
                        height(x->right));

    y->height = 1 + max(height(y->left),
                        height(y->right));

    return y;
}

struct Node* insert(struct Node *root, int value) {
    int balance;

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    balance = getBalance(root);

    /* LL Case */
    if (balance > 1 && value < root->left->data)
        return rightRotate(root);

    /* RR Case */
    if (balance < -1 && value > root->right->data)
        return leftRotate(root);

    /* LR Case */
    if (balance > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RL Case */
    if (balance < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &value);

        root = insert(root, value);
    }

    printf("\nAVL Tree Inorder Traversal: ");
    inorder(root);

    return 0;
}