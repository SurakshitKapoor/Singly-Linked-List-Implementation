#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(struct node *&head, int data) {
    struct node *newNode = new node(data);
    // newNode->data = data;
    // newNode->next = NULL;
    struct node *temp = head;
    if(temp) {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else {
        head = newNode; 
    }
    
    cout << newNode->data << " is inserted \n";
}

void deleteAtEnd(struct node *&head) {
    if(head == NULL) {
        cout << "No node is present \n" ;
        return;
    }
    else if(head -> next == NULL) {
        cout << head->data << " is deleted " << endl;
        delete head;
        head = NULL;
    }
    else {
        struct node *temp= head;
        struct node *delNode = NULL;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delNode = temp->next;
        temp->next = NULL;
        cout << delNode->data << " is deleted" << endl;
        delete delNode;   
    }
}

void deleteAtBeginning(struct node *&head) {
    int data;
    if(head == NULL) {
        cout << "No node is present" << endl;
        return;
    }
    else if(head->next == NULL) {
         data = head->data;
         delete head;
         head = NULL;       //to set head as NULL is like a checkpoint, else it will give garbage value
    }
    else {
        data = head->data;
        struct node *temp = NULL;
        temp = head->next;
        head = temp;
    }
    cout << data << " is deleted" << endl;
}

void deleteAtPosition(struct node *&head, int position) {
    int count = 1;
    int data;
    if(position == 1) {
        deleteAtBeginning(head);
    }
    else {
        struct node *temp = head;
        while(count < position-1) {
            temp = temp->next;
            count++;
        }
        struct node *delNode = temp->next;
        temp->next = delNode->next;
        data = delNode->data;
        delete delNode;
        cout << data << " is deleted from " << position << " position" << endl;
    }
}
void printLinkedList(struct node *head) {
    if(head == NULL) {
        cout << "No node is here !\n";
        return;
    }
    else {
        struct node *temp = head;
        while (temp != NULL) 
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }   
}

int main() {
    cout << "Welcome to single linked list" << endl;
    cout << "\n Deletion is like this :- \n" ;

    struct node * head = NULL;
    insertAtEnd(head, 10);
    insertAtEnd(head, 14);
    insertAtEnd(head, 15);
    insertAtEnd(head, 18);
    insertAtEnd(head, 21);

    deleteAtEnd(head);
    // deleteAtEnd(head);
    
    deleteAtBeginning(head);

    deleteAtPosition(head, 1);
    
    printLinkedList(head);
}