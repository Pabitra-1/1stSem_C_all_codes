#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *root) {
    return root == NULL ? 0 : root->height;
}

int balance(struct Node *root) {
    if (root == NULL)
        return 0;

    return height(root->left) - height(root->right);
}

struct Node* createNode(int value) {
    struct Node *node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = value;
    node->height = 1;
    node->left = node->right = NULL;

    return node;
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *root, int value) {
    int bf;

    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    bf = balance(root);

    if (bf > 1 && value < root->left->data)
        return rightRotate(root);

    if (bf < -1 && value > root->right->data)
        return leftRotate(root);

    if (bf > 1 && value > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && value < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

struct Node* minValueNode(struct Node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct Node* deleteNode(struct Node *root, int key) {
    struct Node *temp;
    int bf;

    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    root->height = 1 + max(height(root->left), height(root->right));
    bf = balance(root);

    /* LL Case */
    if (bf > 1 && balance(root->left) >= 0)
        return rightRotate(root);

    /* LR Case */
    if (bf > 1 && balance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    /* RR Case */
    if (bf < -1 && balance(root->right) <= 0)
        return leftRotate(root);

    /* RL Case */
    if (bf < -1 && balance(root->right) > 0) {
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
    int n, value, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("AVL Tree before deletion: ");
    inorder(root);

    printf("\nEnter element to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("AVL Tree after deletion: ");
    inorder(root);

    return 0;
}