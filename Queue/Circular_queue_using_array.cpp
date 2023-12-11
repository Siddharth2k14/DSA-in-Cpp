#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    CircularQueue(){
        size = 100;
        arr = new int[size];
        front = rear = -1;
    }

    bool enqueue(int value){
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
            // cout<<"Queue is full"<<endl;
            return false;
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
        arr[rear] = value;
        return true;
    }

    int dequeue(){
        if(front == -1){
            // cout<<"Queue is empty"<<endl;
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
};

int main(){
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    return 0;
}