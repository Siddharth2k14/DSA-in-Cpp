//The diameter of a binary tree is the length of the longest path between any two nodes in a tree
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

pair<int,int> DiameterFast(Node* root){
    if(root == NULL){ //Base case
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = DiameterFast(root->left);
    pair<int,int> right = DiameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;
    return ans;
}

int diameter(Node* root){
    return DiameterFast(root).first;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);

    cout<<"The diameter of the given tree is "<<diameter(root)<<endl;
    return 0;
}