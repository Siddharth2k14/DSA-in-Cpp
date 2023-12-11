#include<iostream>
#include<limits.h>
using namespace std;

class stack
{
    int size;
    int* arr;
    int top;

    public:
    stack(int x){
        this->size = x;
        arr = new int[x];
        this->top = -1;
    }

    void push(int data){
        if(this->top == this->size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }

        this->top++;
        arr[this->top] = data;
    }

    int pop(){
        if(this->top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }

        this->top--;
    }

    int Top(){
        if(this->top == -1){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }

        return arr[this->top];
    }

    bool isEmpty(){
        if(this->top == -1){
            return this->top == -1;
        }
    }

    int Size(){
        return this->top + 1;
    }

    bool isFull(){
        return this->top == this->size-1;
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;

    return 0;
}