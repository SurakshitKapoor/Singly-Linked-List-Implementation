#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data);
    if(head == NULL) {
        head = newNode;
    }
    else {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << newNode->data << " is inserted" << endl;

}

void traversingLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "Linked LIst is Empty !" << endl;
        return;
    }
    else {
        struct node *temp = head;
        cout << "On traversing, the elements are :-" << endl;

        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        
    }
}

int main() {
    cout << "In Single Linked List Traversal:-" << endl;
    struct node *head = NULL;

    insertAtEnd(head, 12);
    insertAtEnd(head, 15);
    insertAtEnd(head, 10);
    insertAtEnd(head, 18);
    insertAtEnd(head, 25);
    insertAtEnd(head, 31);

    traversingLinkedList(head);

}