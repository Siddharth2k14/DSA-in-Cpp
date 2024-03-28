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
    cout<<"Enter the data for the node:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting in right "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

void solve(Node* root, int sum, int &max_sum, int len, int &max_len){
    //base case
    if(root == NULL){
        if(len > max_len){
            max_len = len;
            max_sum = sum;
        }
        else if(len == max_len){
            max_sum = max(sum, max_sum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, sum, max_sum, len+1, max_len);
    solve(root->right, sum, max_sum, len+1, max_len);
}

int SumOfLongestBranch(Node* root){
    int len = 0;
    int max_len = 0;
    int sum = 0;
    int max_sum = 0;

    solve(root, sum, max_sum, len, max_len);
    return max_sum;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    cout<<"The sum of the longest branch is "<<SumOfLongestBranch(root)<<endl;
    return 0;
}