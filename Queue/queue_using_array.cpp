#include<iostream>
using namespace std;
#define MAX 5

class queue{
    public:
    int size;
    int* arr;
    int front;
    int rear;

    queue(){
        size = MAX;
        arr = new int[size];
        front = 0;
        rear = 0; 
    }
    
    void push(int x){
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear] = x;
            rear++;
        }
    }

    int pop(){
        if(front == rear){
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    bool isEmpty(){
        return front == rear;
    }

    int Front(){
        if(front == rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int back(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
        
    }

};

int main(){
    queue q;
    q.push(1);
    cout<<"The front element of the stack is : "<<q.Front()<<endl;
    cout<<"The last or end element of the queue is : "<<q.back()<<endl;
    q.push(2);
    cout<<"The front element of the stack is : "<<q.Front()<<endl;
    q.push(3);
    cout<<"The front element of the stack is : "<<q.Front()<<endl;
    q.push(4);
    cout<<"The front element of the stack is : "<<q.Front()<<endl;
    q.push(5);
    cout<<"The front element of the stack is : "<<q.Front()<<endl;
    return 0;
}