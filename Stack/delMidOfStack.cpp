#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>&s, int count, int size){
    //base case
    if(count == size/2){
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    //Recursion
    solve(s, count+1, size);

    s.push(num);
}

void delMid(stack<int>&s, int n){
    int count = 0;
    solve(s, count, n);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int n = s.size();

    delMid(s, n);

    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}