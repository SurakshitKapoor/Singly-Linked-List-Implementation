#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *link;
};

void insertAtBeginning(struct node *&start, int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> link = start;
    start = newNode;
    cout << newNode->data << " is inserted \n";
}

void insertAtEnd(struct node *&start, int data) {
    struct node * temp = start;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> link = NULL;
    temp -> link = newNode;
    cout << newNode->data << " is inserted \n";

}

//Method 1: using count variable
void insertAtPosition (struct node *&start, int data, int position) {
    struct node * newNode = (struct node *)  malloc (sizeof(struct node));
    if(position == 1) {
        insertAtBeginning(start, data);
    }
    else {
        struct node * temp = start;
    int count = 1;
    while (count < position-1)
    {
        temp = temp -> link;
        count ++;
    }
    
    newNode -> data = data;
    newNode -> link = temp->link;
    temp->link = newNode;
    }
    
    cout << start->data << " is inserted at " << position << " position" << endl;
}

//Method 2: w/o using a extra count variable
void insertAtPosition2 (struct node *&start, int data, int position) {
    struct node * newNode = (struct node *)  malloc (sizeof(struct node));
    if(position == 1) {
        insertAtBeginning(start, data);
    }
    else {
        struct node * temp = start;
    while (position > 2)
    {
        temp = temp -> link;
        position --;
    }
    
    newNode -> data = data;
    newNode -> link = temp->link;
    temp->link = newNode;
    }
    
    cout << start->data << " is inserted at " << position << " position" << endl;
}

//printing all elements
void printLinkedList(struct node *&head) {
    struct node *temp = head;
    cout << "Linked List is : \n";
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->link;
    }   
}

int main() {
    cout << "welcome to Linked list world !" << endl;
    cout << "Enter data: " << endl;
    // struct node *start = (struct node *) malloc(sizeof(struct node));
    struct node * start = NULL;
    int data;
    cin >> data;
    insertAtBeginning(start, data);

    cin >> data;
    insertAtBeginning(start, data);
  
    cin >> data;
    insertAtBeginning(start, data);
    
    cin >> data;
    insertAtBeginning(start, data);

    cin >> data;
    insertAtBeginning(start, data);
    
    cin >> data;
    insertAtEnd(start, data);

    cin >> data;
    insertAtPosition(start, data, 2);

    cin >> data;
    insertAtEnd(start, data);

    cin >> data;
    insertAtPosition2(start, data, 1);

    printLinkedList(start);
    return 0;

}
