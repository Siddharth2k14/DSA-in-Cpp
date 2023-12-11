#include<iostream>
using namespace std;

class doubly_queue{
    public:
    int* arr;
    int size;
    int front;
    int rear;

    doubly_queue(){
        size = 100;
        arr = new int[size];
        front = rear = -1;
    }   

    void push_front(int x){
        if(front == 0 && rear == size-1){
            cout<<"Queue is full"<<endl;
        }

        else if(front == -1){
            front = rear = 0;
            arr[front] = x;
        }
        else if (front == 0)
        {
            front = size - 1;
            arr[front] = x;
        }
        else{
            front--;
            arr[front] = x;
        }
    }

    void push_back(int x){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            cout<<"Queue is full"<<endl;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = x;
    }

    int pop_front(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans;
        ans = arr[front];
        arr[front] = -1;

        if(front == -1){
            front = rear = 0;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }

    int pop_back(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else if(rear == -1){
            front = rear = 0;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
    }

    int get_front(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int get_rear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool ifFull(){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};


int main(){
    doubly_queue dq;
    dq.push_front(1);
    dq.push_back(2);
    cout<<dq.get_front()<<endl;
    cout<<dq.get_rear()<<endl;
    return 0;
}