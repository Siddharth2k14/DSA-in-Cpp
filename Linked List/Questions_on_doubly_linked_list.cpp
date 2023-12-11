//1->Find the length of the doubly linked list.
/*#include<iostream>
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

int length(node* head){
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    return count;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
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
    int len = length(head);
    cout<<len<<endl;
    return 0;
}*/

//2->Find the largest node in the doubly linked list.
/*#include<iostream>
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

int largest(node* head){
    node* temp = head;
    node* ptr = head;
    while(temp != NULL){
        if(temp->data > ptr->data){
            ptr = temp;
        }
        temp = temp->next;
    }
    return ptr->data;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
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
    
    int l = largest(head);
    cout<<l<<endl;
    return 0;
}*/

//3->Find the pairs with given sum in doubly linked list
/*#include<iostream>
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

void pairs_of_given_sum(node* head, int target){
    node* first = head;
    node* second = head;
    
    while(second->next != NULL){
        second = second->next;
    }

    while(first != second && first->prev != second){
        int sum = first->data + second->data;
        if(sum == target){
            cout<<first->data<<","<<second->data;
            first = first->next;
            second = second->prev;
        }

        else if(sum > target){
            second = second->prev;
        }

        else{
            first = first->next;
        }
    }
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
    node* fourth = NULL;
    node* fifth = NULL;
    node* sixth = NULL;
    node* seventh = NULL;

    // Allocate 3 nodes in the heap
    head = new node(1);
    second = new node(2);
    third = new node(4);
    fourth = new node(5);
    fifth = new node(6);
    sixth = new node(8);
    seventh = new node(9);

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->next = seventh;
    sixth->prev = fifth;

    seventh->next = NULL;
    seventh->prev = sixth;

    display(head);
    pairs_of_given_sum(head, 7);
    return 0;
}*/

//4->Check whether a doubly linked list of characters is palindrome or not.
#include<iostream>
using namespace std;

class node{
    public:
    char data;
    node* next;
    node* prev;

    node(char val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" "<<"<->"<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

node* reverse(node** head){
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

    return *head;
}

int check_for_palindrome(node* head){
    node* temp = head;
    if(reverse(&head) == temp){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
    node* fourth = NULL;
    node* fifth = NULL;
    node* sixth = NULL;
    node* seventh = NULL;

    // Allocate 3 nodes in the heap
    head = new node('a');
    second = new node('b');
    third = new node('c');
    fourth = new node('d');
    fifth = new node('c');
    sixth = new node('b');
    seventh = new node('l');

    head->next = second;
    head->prev = NULL;

    second->next = third;
    second->prev = head;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = sixth;
    fifth->prev = fourth;

    sixth->next = seventh;
    sixth->prev = fifth;

    seventh->next = NULL;
    seventh->prev = sixth;

    display(head);
    reverse(&head);
    display(head);

    if(check_for_palindrome(head) == 1){
        cout<<"It is palindrome"<<endl;
    }
    else{
        cout<<"It is not"<<endl;
    }
    return 0;
}