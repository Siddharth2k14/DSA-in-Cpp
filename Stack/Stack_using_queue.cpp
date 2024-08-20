#include<bits\stdc++.h>
using namespace std;

int size = 0;
class Stack{
    int size;
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int data){
        q2.push(data);
        size++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        size--;
    }

    int top(){
        return q1.front();
    }

    int Size(){
        return size;
    }

    bool isEmpty(){
        if(q1.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    cout<<st.isEmpty()<<endl;
    return 0;
}