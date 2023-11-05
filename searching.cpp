#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode= new node(data);

    if(head == NULL) {
        head = newNode;
    }
    else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << newNode->data << " is inserted" << endl;
}

void searchData(struct node *&head, int data) {
    if(head == NULL) {
        cout << "No node is here" << endl;
        return;
    }

    struct node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if(temp->data == data){
            cout << data << " is found at " << position << " position" << endl;
            return;
        }
        temp = temp->next;
        position++;
    } 
}

void printLinkedList(struct node *&head) {
    if(head == NULL) {
        cout << "No node is present" << endl;
        return;
    }
    else {
        struct node *temp = head;
        cout << "Linked List is :- \n";
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
        
    }
}

int main() {
    cout << "Searching in Linked List:-" << endl;
    struct node *head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 13);
    insertAtEnd(head, 6);
    insertAtEnd(head, 62);
    insertAtEnd(head, 51);
    insertAtEnd(head, 25);

    printLinkedList(head);

    searchData(head, 51);
}