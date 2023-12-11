#include<iostream>
#include<limits.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

class stack{
    node* head;
    int capacity;
    int current_size;

    public:
    stack(int x){
        capacity = x;
        current_size = 0;
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    bool isFull(){
        return current_size == capacity;
    }

    void push(int x){
        if(isFull() == 1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        node* new_node = new node(x);
        new_node->next = head;
        head = new_node;
        current_size++;
    }

    int pop(){
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        node* new_head = head->next;
        head->next = NULL;
        node* todelete = head;
        int result = todelete->data;
        delete todelete;
        head = new_head;
        return result;
    }

    int size(){
        return current_size;
    }

    int get_top(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.get_top()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.isEmpty()<<endl;
    return 0;
}