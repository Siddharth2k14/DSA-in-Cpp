#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

void rearrangeQueue(queue<int> &q){
    int half = q.size()/2;
    stack<int> st;

    for(int i = 0; i < half; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

    for(int i = 0; i < half; i++){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }

    for(int i = 0; i < half; i++){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }

    while(!st.empty()){
        int val = st.top();
        st.pop();
        q.push(val);

        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main(){
    queue<int> q;
    int n;
    cout << "Enter the number of elements in the queue here" << endl;
    cin >> n;

    int val;
    cout << "Enter the elements of the queue here" << endl;
    for(int i = 0; i < n; i++){
        cin >> val;
        q.push(val);
    }

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout << ele << " ";
    }cout << endl;

    rearrangeQueue(q);

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        cout << ele << " ";
    }cout << endl;

    return 0;
}