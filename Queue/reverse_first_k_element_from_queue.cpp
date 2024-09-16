#include<iostream>
#include<stack>
#include<queue>
using namespace std;

queue<int> reverseElements(queue<int> q, int k){
    //Step1
    stack<int> st;
    for(int i = 0; i < k; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }

    //Step2
    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

    //Step3
    int t = q.size() - k;
    while(t--){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }

    return q;
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
    display(q);

    queue<int> rq = reverseElements(q, 3);

    display(rq);

    return 0;
}