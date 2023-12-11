#include<iostream>
#include<stack>
#include<math.h>
#include<limits.h>
using namespace std;

/*class node{
    public:
    int data;
    node* next;
    node(int d){
        data = d;
        next = NULL;
    }
};

class stack{
    node* head;
    int capacity;
    int current_size;

    public:
    stack(int x){
        capacity = x;
        current_size = 0;
        head = NULL;
    }

    bool isEmpty(){
        return head == NULL;
    }

    bool isFull(){
        return current_size == capacity;
    }

    void push(int x){
        if(isFull() == 1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        node* new_node = new node(x);
        new_node->next = head;
        head = new_node;
        current_size++;
    }

    int pop(){
        if(head == NULL){
            cout<<"Stack Underflow"<<endl;
            return INT_MIN;
        }
        node* new_head = head->next;
        head->next = NULL;
        node* todelete = head;
        int result = todelete->data;
        delete todelete;
        head = new_head;
        return result;
    }

    int size(){
        return current_size;
    }

    int get_top(){
        if(head == NULL){
            cout<<"Underflow"<<endl;
            return INT_MIN;
        }
        return head->data;
    }
};*/

//Evaluate Postfix expression.
/*int postfix(string s){
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

//Evaluate Prefix expression.
int prefix(string s){
    stack<int> st;
    for(int i = s.length()-1; i>=0; i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;
            case '-':
                st.push(op1-op2);
                break;
            case '*':
                st.push(op1*op2);
                break;
            case '/':
                st.push(op1/op2);
                break;
            case '^':
                st.push(pow(op1,op2));
                break;
            }
        }
    }
    return st.top();
}

int main(){
    cout<<postfix("35+64-*41-2^+")<<endl;
    // cout<<prefix("-+7*45+21")<<endl;
    return 0;
}*/

//2->Infix To Postfix
/*#include<bits/stdc++.h> //It includes all basics operations of stacks
using namespace std;

int precedence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '/' || c == '*'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

void infix_to_postfix(string s){
    stack<char> st;
    string result;

    for(int i = 0; i < s.length(); i++){
        char c = s[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <='Z') || (c >= '0' && c <= '9')){
            result += c;
        }

        else if(c == '('){
            st.push('(');
        }

        else if(c == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && (precedence(c) <= precedence(st.top()))){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    cout<<result<<endl;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_postfix(exp);
    return 0;
}*/

//3->Postfix To Infix.
/*#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

string postfix_to_infix(string exp){
    stack<string> s;
    for(int i = 0; exp[i] != '\0'; i++){
        if(isOperator(exp[i])){
            string op(1, exp[i]);
            s.push(op);
        }

        else{
            string op1 = s.top();
            s.pop();
            string op2  = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

int main(){
    string exp = "abcd^e-fgh*+^*+i-";
    cout<<postfix_to_infix(exp);
    return 0;
}*/

//4->Infix To Prefix
/*\#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c){
    return (!isalpha(c) && !isdigit(c));
}

int precendence(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infix_to_postfix(string infix){
    infix = '(' + infix + ')';
    int l = infix.size();
    stack<char> st;
    string result;

    for(int i = 0; i < l; i++){
        if(isalpha(infix[i]) || isdigit(infix[i])){
            result += infix[i];
        }

        else if(infix[i] == '('){
            st.push('(');
        }

        else if(infix[i] == ')'){
            while(st.top() != '('){
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            if(isOperator(st.top())){
                if(infix[i] == '^'){
                    while(precendence(infix[i]) <= precendence(st.top())){
                        result += st.top();
                        st.pop();
                    }
                }

                else{
                    while(precendence(infix[i]) < precendence(st.top())){
                        result += st.top();
                        st.pop();
                    }
                }

                st.push(infix[i]);
            }
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

string infix_to_prefix(string infix){
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infix_to_postfix(infix);
 
    // Reverse postfix
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}

int main(){
    cout<<infix_to_prefix("x+y*z/w+u")<<endl;
    return 0;
}*/

//5->Prefix To Infix
/*#include<bits/stdc++.h>
using namespace std;

bool isOperator(char x){
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '%':
        return true;
    }
    return false;
}

string prefix_to_infix(string exp){
    stack<string> s;
    int length = exp.size();
    for(int i = length - 1; i >= 0; i--){
        if(isOperator(exp[i])){
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = "(" + op1 + exp[i] + op2 + ")";
            s.push(temp);
        }

        else{
            s.push(string(1, exp[i]));
        }
    }
    return s.top();
}

int main(){
    string pre_exp = "*-A/BC-/AKL";
    cout << "Infix : " << prefix_to_infix(pre_exp);
    return 0;
}*/