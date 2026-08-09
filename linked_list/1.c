#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};
// It creates a new node 
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->val = data;
    newNode->next = NULL;

    return newNode;
}

// this function inserts a new node at the end of the linked list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);

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


int main(){
    struct Node *head=NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    

}