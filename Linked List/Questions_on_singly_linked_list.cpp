//1->Search an element in the given linked list(iterative and recursive)
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

// void fill(node** head, int val){
//     node* n = new node();
//     n->data = val;
//     n->next = *head;
//     *head = n;
// }

//iterative approach
bool search_iterative(node* ptr, int key){
    while(ptr!=NULL){
        if(ptr->data == key){
            return true;
        }
        ptr=ptr->next;
    }
    return false;
}

//recursive approach
bool search_recursive(node* ptr, int key){
    if(ptr == NULL){
        return false;
    }

    if(ptr->data == key){
        return true;
    }

    return search_recursive(ptr->next, key);
}

void display(node* ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
    }
    cout<<endl;
}
    

int main()
{
    node* head = NULL;
    node* second = NULL;
    node* third = NULL;
    node* fourth = NULL;

    head = new node();
    second = new node();
    third = new node();
    fourth = new node();

    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    if(search_recursive(head, 5)==1){
        cout<<"Search is successful"<<endl;
    }
    else{
        cout<<"Search is not possible"<<endl;
    }
    return 0;
}*/

//2->Find the length of the linked list(iterative and recursive)
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

//iterative
int length_iterative(node* ptr){
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}

//recursive
int length_recursive(node* ptr){
    if(ptr == NULL){
        return 0;
    }
    else{
        return 1 + length_recursive(ptr->next);
    }
}
void fill(node** ptr, int val){
    node* n = new node();
    n->data = val;
    n->next = *ptr;
    *ptr = n;
}

void display(node* ptr){
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main(){
    node* head = NULL;
    fill(&head, 1);
    fill(&head, 2);
    fill(&head, 3);
    fill(&head, 4);
    
    display(head);
    // int len = length_iterative(head);
    cout<<length_recursive(head)<<endl;
    return 0;
}*/

//3->Reverse the linked list(iterative and recursive)
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

//iterative
node* reverse_iterative(node* head){
    node* prev_ptr = NULL;
    node* current_ptr = head;
    node* next_ptr;
    while(current_ptr != NULL){
        next_ptr = current_ptr->next;
        current_ptr->next = prev_ptr;

        prev_ptr = current_ptr;
        current_ptr = next_ptr;
    }
    return prev_ptr;
}

//recursive
node* reverse_recursive(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

//To print the linked list
void print(node* head){
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
}

//Input the data in the linked list
void push(node** head, int data){
        node* temp = new node();
        temp->data = data;
        // temp->next = NULL;
        temp->next = *head;
        *head = temp;
}

int main(){
    node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);

    print(head);
    node* newhead = reverse_iterative(head);
    print(newhead);
    return 0;
}*/

//4->Find the middle value of linked list
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void push(node** head, int data){
        node* temp = new node();
        temp->data = data;
        // temp->next = NULL;
        temp->next = *head;
        *head = temp;
}

int length_iterative(node* ptr){
    int count = 0;
    while(ptr != NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}

int mid(node* head){
    int len = length_iterative(head);
    int midd = len/2;
    return midd;
}

void mid_value(int middle, node* head){
    middle = mid(head);
	node* temp = head;
    node* ptr = head->next;
	while(middle--){
		temp = temp->next;
	}
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = temp;
	// return temp->data;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    print(head);

    int len = length_iterative(head);
	cout<<"The length of the Linked list is "<<len<<endl;
	int m = mid(head);
	// cout<<"The middle index is "<<m<<endl;
	mid_value(m, head);
	// cout<<"The middle value of Linked list is "<<a<<endl;
    print(head);
    return 0;
}*/

//5->Nth node from the last of the Linked List
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void node_from_last(node* head, int N){
    node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }

    if(count < N){
        return;
    }

    temp = head;

    for(int i = 1; i < count-N+1; i++){
        temp = temp->next;
    }
    cout<<temp->data<<endl;
}

void push(node** head, int data){
    node* temp = new node();
    temp->data = data;
    temp->next = NULL;
    temp->next = *head;
    *head = temp;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    print(head);
    node_from_last(head, 4);
    return 0;
}*/

//6->To make middle as the head node
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

void middle_as_head(node** head){
    if(head == NULL){
        return;
    }

    node* one_ptr = *head;
    node* sec_ptr = *head;
    node* prev_ptr = NULL;

    while(sec_ptr != NULL && sec_ptr->next != NULL){
        prev_ptr = one_ptr;
        sec_ptr = sec_ptr->next->next;
        one_ptr = one_ptr->next;
    }
    prev_ptr->next = prev_ptr->next->next;
    one_ptr->next = *head;
    *head = one_ptr;
}

void push(node** head, int data){
    node* temp = new node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    // push(&head, 6);
    // push(&head, 7);
    print(head);
    middle_as_head(&head);
    print(head);
    return 0;
}*/

//7->To add 1 to the given linked list
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next_ptr;
    while(curr != NULL){
        next_ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_ptr;
    }
    return prev;
}

//To create a new node
node *newNode(int data){
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

node* add_one(node* head){
    head = reverse(head);
    node* current = head;
    node* prev = head;
    int sum = current->data + 1;
    current->data = sum % 10;
    int carry = sum /10;

    while(current != NULL){
        sum = current->data + carry;
        current->data = sum % 10;
        carry = sum / 10;
        prev = current;
        current =  current->next;
    }

    if(carry != 0){
        prev->next = newNode(carry);
    }
    head = reverse(head);
    return head;
}

void push(node** head, int data){
    node* temp = new node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    push(&head, 9);
    push(&head, 9);
    push(&head, 9);
    print(head);
    node* new_ll = add_one(head);
    print(head);
    return 0;
}*/

//8->To add two Linked List
/*#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x){
        data = x;
        next = NULL;
    }
};

node* reverse(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next_ptr;
    while(curr != NULL){
        next_ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_ptr;
    }
    return prev;
}

//To create a new node
/*node *newNode(int data){
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}*/

/*void insertattail(node* head, node* tail, int val){
    node* temp = new node(val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }

    else{
        tail->next = temp;
        tail = temp;
    }
}

node* add(node* first, node* second){
    int carry = 0;
    node* anshead = NULL;
    node* anstail = NULL;
    while(first != NULL && second != NULL){
        int sum = carry + first->data + second->data;
        int digit = sum%10;

        insertattail(anshead, anstail, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }
    while(first != NULL){
        int sum = carry + first->data;
        int digit = sum%10;
        insertattail(anshead, anstail, digit);
        carry = sum/10;
        first = first->next;
    }
    while(second != NULL){
        int sum = carry + second->data;
        int digit = sum%10;
        insertattail(anshead, anstail, digit);
        carry = sum/10;
        second = second->next;
    }
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        einsertattail(anshad, anstail, digit);
        carry = sum/10;
    }
    return anshead;
}

node* add_two_list(node* first, node* second){
    //reverse the Linked Lists
    first = reverse(first);
    second = reverse(second);

    //add the 2 linked lists
    node* ans = add(first, second);

    //reverse the ans linked list
    ans = reverse(ans);
}

void push(node** head, int data){
    node* temp = new node(data);
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void print(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head1 = NULL;
    push(&head1, 3);
    push(&head1, 4);
    // push(&head1, 3);
    print(head1);

    node* head2 = NULL;
    push(&head2, 5);
    push(&head2, 4);
    push(&head2, 3);
    print(head2);
    node* h = add_two_list(head1, head2);
    print(h);
    return 0;
}*/

//9->Find the intersection of two linked list.
/*#include<iostream>
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

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void push(node** head, int data){
    node* temp = new node(data);
    temp->next = *head;
    *head = temp;
}

int length(node* &head){
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

int intersection(node* &head1, node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if(l1>l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }    
        d--;
    }

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

void intersect(node* &head1, node* &head2, int pos){
    node* temp1 = head1;
    node* temp2 = head2;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }

    while(temp2->next != NULL){
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int main(){
    node* head1 = NULL;
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 3);
    push(&head1, 4);
    push(&head1, 5);
    display(head1);

    node* head2 = NULL;
    push(&head2, 2);
    push(&head2, 4);
    push(&head2, 6);
    push(&head2, 8);
    push(&head2, 10);
    display(head2);
    intersect(head1, head2,4);
    cout<<intersection(head1, head2)<<endl;
    return 0;
}*/

//10->Merge two linked lists in the sorted order.
/*#include<iostream>
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

node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummy_node = new node(-1);
    node* p3 = dummy_node;

    while(p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
    }

    while(p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while(p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummy_node->next;
}

void push(node** head, int data){
    node* temp = new node(data);
    temp->next = *head;
    *head = temp;
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
    node* head1 = NULL;
    node* head2 = NULL;
    push(&head1, 7);
    push(&head1, 5);
    push(&head1, 4);
    push(&head1, 1);
    push(&head2, 6);
    push(&head2, 3);
    push(&head2, 2);

    display(head1);
    display(head2);

    node* new_head = merge(head1, head2);
    display(new_head);
    return 0;
}*/