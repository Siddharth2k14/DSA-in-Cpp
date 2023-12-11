#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* BuildTree(Node* root){
    cout<<"Enter the data for the node: "<<endl;
    int value;
    cin>>value;
    root = new Node(value);

    if(value == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left "<<value<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting in right "<<value<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void solve(Node* root, vector<int> &ans, int level){
    // base case
    if(root == NULL){
        return;
    }
    if(level == ans.size()){
        ans.push_back(root->data);
    }

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    vector<int> ans = leftView(root);
    for(int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}