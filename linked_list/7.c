#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->val = data;
    newNode->next = NULL;

    return newNode;
}
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

void display(struct Node *head){
    while(head){
        printf("%d->",head->val);
        
        head = head->next;
    }
    printf("NULL\n");
}


void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next = NULL;

    while (curr != NULL) {
        // Save the next node
        next = curr->next;

        // Reverse the link
        curr->next = prev;

        // Move prev and curr forward
        prev = curr;
        curr = next;
    }

    // prev is the new head
    *head = prev;
}

int main(){
    struct Node *head=NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    display(head);
    reverse(&head);
    display(head);

return 0;

}