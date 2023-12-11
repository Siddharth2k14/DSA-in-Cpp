#include<iostream>
#include<vector>
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

void traversalLeft(Node* root, vector<int> &ans){
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left != NULL){
        traversalLeft(root->left, ans);
    }
    else{
        traversalLeft(root->right, ans);
    }
}

void traversalLeaf(Node* root, vector<int> &ans){
    //base case
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    traversalLeaf(root->left, ans);
    traversalLeaf(root->right, ans);
}

void traversalRight(Node* root, vector<int> &ans){
    //base case
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right != NULL){
        traversalRight(root->right, ans);
    }
    else{
        traversalRight(root->left, ans);
    }

    ans.push_back(root->data);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    ans.push_back(root->data);
    
    //traverse the left part
    traversalLeft(root->left, ans);

    //left subtree
    traversalLeaf(root->left, ans);

    //right subtree
    traversalLeaf(root->right, ans);

    //traverse right part
    traversalRight(root->right, ans);

    return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    vector<int> ans = boundary(root);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}