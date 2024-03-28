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

pair<bool,int> isSumFast(Node* root){
    //base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumFast(root->left);
    pair<bool,int> rightAns = isSumFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;

    pair<bool,int> ans;
    if(left and right and condn){
        ans.first = true;
        ans.second = 2*root->data;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isSumTree(Node* root){
    return isSumFast(root).first;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    if(isSumTree(root) == 1){
        cout<<"The given tree is a sumtree"<<endl;
    }
    else{
        cout<<"Not a Sum Tree"<<endl;
    }
    return 0;
}