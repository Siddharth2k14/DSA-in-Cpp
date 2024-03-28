#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtEnd(node** head, int val){
    if(*head == NULL){
        node* new_node = new node(val);
        new_node->next = new_node->prev = new_node;
        *head = new_node;
        return;
    }
    node* last = (*head)->prev;
    node* n = new node(val);
    n->next = *head;
    (*head)->prev = n;
    n->prev = last;
    last->next = n;
}

void insertAtBeginning(node* &head, int val){
    node* last = head->prev;
    node* n = new node(val);
    n->next = head;
    n->prev = last;
    last->next = n;
    head->prev = n;
    head = head->prev;
}

void insertAtMid(node* head, int node_val, int data){
    node* n = new node(node_val);
    node* temp = head;
    while(temp->data != data){
        temp = temp->next;
    }

    node* next_node = temp->next;
    temp->next = n;
    n->prev = temp;
    next_node->prev = n;
    n->next = next_node;
}

void deleteAtHead(node* &head){
    node* temp = head;
    node* todelete = temp;
    node* last = temp->prev;
    last->next = temp->next;
    temp->next->prev = last;
    head = head->next;

    delete temp;
}

void deleteAtpos(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
    }
    node* temp = head;
    int count = 1;
    while(count != pos-1){
        temp = temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

void display(node* head){
    node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

int main(){
    node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    display(head);
    insertAtBeginning(head, 0);
    // insertAtMid(head, 5, 4);
    // deleteAtHead(head);
    // deleteAtpos(head, 4);
    display(head);
    return 0;
}