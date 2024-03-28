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

    cout<<"Enter the data for inserting in the left "<<data<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting in the right "<<data<<endl;
    root->right = BuildTree(root->right);

    return root;
}

Node* lca(Node* root, int n1, int n2){
    // base case
    if(root == NULL){
        return root;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    int n1, n2;
    cout<<"Enter the values of any two nodes:"<<endl;
    cin>>n1>>n2;
    Node* ans = lca(root, n1, n2);
    cout<<"The Lowest common ancestor of "<<n1<<" and "<<n2<<" is "<<lca(root, n1, n2)<<endl;
    return 0;
}