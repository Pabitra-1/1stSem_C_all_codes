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

void mirror(struct Node *root) {
    struct Node *temp;

    if (root == NULL)
        return;

    temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("\nOriginal Inorder: ");
    inorder(root);

    mirror(root);

    printf("\nMirror Inorder: ");
    inorder(root);

    return 0;
}