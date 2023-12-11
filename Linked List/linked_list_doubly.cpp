#include<iostream>
using namespace std;

//To create a new node.
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

//To insert a node at first position of the Linked list.
void insert_at_first(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}

//To insert a node at end position of the Linked list.
void insert_at_end(node* &head, int value){
    if(head == NULL){
        insert_at_first(head, value);
        return;
    }
    node* n = new node(value);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

//To insert a node after the given node.
void insert_after_given_node(node* prev_node, int value){
    node* n = new node(value);
    n->next = prev_node->next;
    prev_node->next = n;
    n->prev = prev_node;

    if(n->next != NULL){
        n->next->prev = n;
    }
}

//To insert a node before the given node.
void insert_before_given_node(node* next_node, int value){
    node* n = new node(value);
    next_node->prev->next = n;
    n->next = next_node;
    n->prev = next_node->prev;
    next_node->prev = n;
}

//To reverse the Linked list.
void reverse(node** head){
    node* temp = NULL;
    node* current = *head;
    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if(temp != NULL){
        *head = temp->prev;
    }
}

//Delete the node from the head
node* delete_at_head(node* head){
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
    head->prev = NULL;
    return head;
}

//Delete the node from any position
node* delete_position(node* &head, int pos){
    if(pos == 1){
        delete_at_head(head);
    }
    node* temp = head;
    int count = 1;
    while(temp != NULL && count != pos){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    delete temp;
    return head;
}

//To display the Linked list.
void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
 
    // Allocate 3 nodes in the heap
    head = new node(1);
    second = new node(2);
    third = new node(3);
 
    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = NULL;
    third->prev = second;

    display(head);
    // insert_before_given_node(head, 6);
    // insert_at_first(head, 0);
    // insert_at_end(head, 4);
    // insert_after_given_node(second, 5);
    // reverse(&head);
    
    node* h = delete_position(head, 1);
    display(h);

    return 0;
}