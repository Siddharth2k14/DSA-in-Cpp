#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

// void fill(node **head, int val){
//     node *new_node = new node(val);
//     new_node->next = *head;
//     *head = new_node;
// }

void InsertAtHead(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void Insertafternode(node* prev_node, int val){
    node* n = new node(val);
    n->next = prev_node->next;
    prev_node->next = n;

}

void deleteAtHead(node* &head){
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head = head->next;

    delete todelete;
}

node* deleteAtPos(node* &head, int pos){
    if(pos == 1){
        node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        node* todelete = head;
        temp->next = head->next;
        head = head->next;

        delete todelete;
        return head;
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
    return head;
}

void splitList(node *head, node **head1_ref, node **head2_ref){
    node *slow_ptr = head;
    node *fast_ptr = head;
     
    if(head == NULL)
        return;
     
    /* If there are odd nodes in the circular list then
       fast_ptr->next becomes head and for even nodes
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head &&
          fast_ptr->next->next != head)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
     
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
         
    /* Set the head pointer of first half */
    *head1_ref = head;
         
    /* Set the head pointer of second half */
    if(head->next != head)
        *head2_ref = slow_ptr->next;
         
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next;
         
    /* Make first half circular */
    slow_ptr->next = head;
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

int main(){
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
    node* fourth = NULL;

    // Allocate 3 nodes in the heap
    head = new node(1);
    second = new node(2);
    third = new node(3);
    fourth = new node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next =  head;

    display(head);
    // InsertAtTail(head, 4);
    // InsertAtHead(head, 0);
    // Insertafternode(second, 5);
    node* h = deleteAtPos(head, 1);
    // splitList(head, &second, &third);
    display(h);
    // display(second);
    // display(third);
    return 0;
}