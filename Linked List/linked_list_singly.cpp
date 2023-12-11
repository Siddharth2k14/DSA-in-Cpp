#include<iostream>
using namespace std;

//Create a node
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

//Insert the node at first of the Linked List
void insertatfirst(node **head, int val){
    node *n = new node(val);
    n->next=*head;
    *head=n;
}

//Pushing the node in the Linked List
void fill(node **head, int val){
    node *new_node = new node(val);
    new_node->next = *head;
    *head = new_node;
}

//Insert a node after the given node
void insertAfter(node *prev_node, int val){
    if(prev_node==NULL){
        cout<<"The given node doesn't exist";
        return;
    }

    node *new_node = new node(val);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

//Insert a node at the end of the Linked List
void append(node **head, int val){
    node *new_node = new node(val);
    node *last = *head;

    if(*head == NULL){
        *head = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

// void deletion(node* head, int val){

//     //If linked list is empty
//     if(head == NULL){
//         return;
//     }

//     //If linked list has only one node
//     if(head->next == NULL){
//         // deleteAtHead(head);
//         return;
//     }

//     node* temp = head;
//     while(temp->next->data != val){
//         temp = temp->next;
//     }
//     node* todelete = temp->next;
//     temp->next = temp->next->next;

//     delete todelete;
// }

// void deleteAtHead(node* head){
//     node* temp = head;
//     head = head->next;

//     delete temp;
// }

void display(node* ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    };
    cout<<"NULL"<<endl;
}

node* deleteatFirst(node* head){
    node* ptr = head;
    head = head->next;

    delete ptr;
    return head;
}

node* deleteatindex(node* head, int index){
    node* p = head;
    node* ptr = head->next;

    for(int i = 0; i < index-1; i++){
        p = p->next;
        ptr = ptr->next;
    }

    p->next = ptr->next;
    delete ptr;
    return head;
}

node* deleteatend(node* head){
    node* p = head;
    node* ptr = head->next;
    while(ptr->next != NULL){
        p = p->next;
        ptr = ptr->next;
    }

    p->next = NULL;
    delete ptr;
    return head;
}

node* deletebyvalue(node* head, int value){
    node* p = head;
    node* ptr = head->next;

    while(ptr->data != value && ptr->next != NULL){
        p = p->next;
        ptr = ptr->next;
    }

    if(ptr->data == value){
        p->next = ptr->next;
        delete ptr;
    }
    return head;
}

int main(){
    node* head = NULL;
    fill(&head, 10);
	fill(&head, 9);
	fill(&head, 8);
	fill(&head, 7);
	fill(&head, 6);
	fill(&head, 5);
	fill(&head, 4);
	fill(&head, 3);
	fill(&head, 2);
	fill(&head, 1);
    display(head);
    // append(&head, 5);
    // insertAfter(head, 6);
    // insertatfirst(&head, 0);
    // deleteAtHead(head);
    // node* new_head = deleteatFirst(head);
    // node* new_head = deleteatindex(head, 3);
    // node* new_head = deleteatend(head);
    node* new_head = deletebyvalue(head, 2);
    display(new_head);
    return 0;
}