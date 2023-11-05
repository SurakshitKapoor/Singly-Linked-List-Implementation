#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

//Method 1: Pass By Reference using & in parameters 
void insertAtBeginning(struct node *&head, int data) {
    struct node *temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
    cout << temp->data << " is inserted" << endl;

}

//Method 2: Pass by value of pointer variable
struct node * insertAtBeginning2(struct node *head, int data) {
    struct node *newNode = new node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    cout << head -> data << " is inserted \n";
    return head;

}

//Method 3: Pass by Reference using pointer variable
void insertAtBeginning3(struct node **head, int data) {
    struct node *newNode = new node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;

    cout << (*head)->data << " is inserted \n";

}

//printing all elements
void printLinkedList(struct node *&head) {
    struct node *temp = head;
    cout << "Linked List is : \n";
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    
}
int main() {
    cout << "Insertion in single linked list:-" << endl;
    struct node *head = NULL;

    insertAtBeginning(head, 15);

    head = insertAtBeginning2(head, 20);

    insertAtBeginning(head, 12);

    insertAtBeginning(head, 18);

    insertAtBeginning3(&head, 24);

    head = insertAtBeginning2(head, 30);

    insertAtBeginning(head, 58);
    
    insertAtBeginning3(&head, 45);

    head = insertAtBeginning2(head, 50);

    printLinkedList(head);
}