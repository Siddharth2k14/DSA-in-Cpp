#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int element){
    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();

    insertAtBottom(s, element);

    s.push(num);
}

void reverseStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, num);
}

void display(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << endl;
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    display(s);

    reverseStack(s);

    display(s);
    return 0;
}