#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse_queue(queue<int> &q){
    stack<int> st;

    while(!q.empty()){
        int element = q.front();
        q.pop();
        st.push(element);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }
}

void display(queue<int> q){
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    display(q);

    reverse_queue(q);

    display(q);

    return 0;
}