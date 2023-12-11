#include<bits/stdc++.h>
using namespace std;

int top = -1;
stack<int> st;
void push(int number){
    stack<int> st;

    while(number != 0){
        top++;
        st.top() = number;
        number--;
    }
}

void factorial_using_stack(){
    int factorial = 1;
    while(top != -1){
        factorial *= st.top();
        top--;
    }
    cout<<factorial<<endl;
}

int main(){
    int number;
    cout<<"Enter the number: "<<endl;
    cin>>number;

    if(number < 0){
        cout<<"Invalid Input"<<endl;
    }
    else{
        push(number);
        cout<<"The factorial of the given number"<<number<<" is ";
        factorial_using_stack();
    }

    return 0;
}