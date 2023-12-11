#include<iostream>
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
    cout<<"Enter the data for the Node: "<<endl;
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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right)+1;
    return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    cout<<"The height of the tree is "<<height(root)<<endl;
    return 0;
}