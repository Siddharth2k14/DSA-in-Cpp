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
    cout<<"Enter the data for the node"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting to the left of the "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting to the right of the "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void solve(Node* root, int k, int &count, vector<int> path){
    //base case
    if(root == NULL){
        return;
    }

    path.push_back(root->data);
    
    //call for left
    solve(root->left, k, count, path);

    //call for right
    solve(root->right, k, count, path);

    int size = path.size();
    int sum = 0;
    for(int i = size-1; i >= 0; i--){
        sum = sum + path[i];
        if(sum == k){
            count = count + 1;
        }
    }

    path.pop_back();
}

int sumK(Node* root, int k){
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    cout<<"Sum of k is "<<sumK(root, 3)<<endl;
    return 0;
}