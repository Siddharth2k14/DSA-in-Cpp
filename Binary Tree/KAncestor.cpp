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

Node* solve(Node* root, int &k, int node){
    //base case
    if(root == NULL){
        return NULL;
    }
    if(root->data == node){
        return root;
    }

    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int KAncestor(Node* root, int k, int node){
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans->data == node){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    cout<<"Kth ancestor of a given value is: "<<KAncestor(root, 2, 4)<<endl;
    return 0;
}