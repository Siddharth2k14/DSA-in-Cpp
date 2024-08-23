#include<iostream>
#include<stack>
using namespace std;

void sorted_insertion(stack<int> &stack, int num){
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
    }

    int ele = stack.top();
    stack.pop();

    sorted_insertion(stack, num);

    stack.push(ele);
}

void sortStack(stack<int> &stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    sortStack(stack);

    sorted_insertion(stack, num);
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
    s.push(-11);
    s.push(3);
    s.push(-1);
    s.push(5);

    display(s);

    sortStack(s);

    display(s);

    return 0;
}