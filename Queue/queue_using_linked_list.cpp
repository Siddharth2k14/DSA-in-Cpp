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

class que{
    node* front;
    node* rear;
    int size;

    public:
    que(){
        front = rear = NULL;
        this->size = 0;
    }

    void push(int x){
        node* n = new node(x);
        if(front = NULL){
            front = rear = n;
        }
        rear->next = n;
        rear = n;
        this->size++;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }
        node* temp = front;
        front = front->next;

        delete temp;
        this->size--;
    }

    int peek(){
        if(front == NULL){
            cout<<"No element is present in the queue"<<endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }

};

int main(){
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;
    // if(q.isEmpty()){
    //     cout<<"Queue is empty"<<endl;
    // }
    // else{
    //     cout<<"Queue is not empty"<<endl;
    // }
    return 0;
}