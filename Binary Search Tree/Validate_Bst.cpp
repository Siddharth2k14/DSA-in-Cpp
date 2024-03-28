#include<iostream>
#include<limits.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool isBst(node* root, int min, int max){
    //base case
    if(root == NULL){
        return true;
    }
    
    if(root->data >= min && root->data <= max){
        bool left = isBst(root->left, min, root->data);
        bool right = isBst(root->right, root->data, max);
        return left && right;
    }

    else{
        return false;
    }
}

bool validateBst(node* root){
    return isBst(root, INT_MIN, INT_MAX);
}

node* InsertIntoBst(node* &root, int data){
    //base case
    if(root == NULL){
        root = new node(data);
        return root;
    }

    //if data is greater than the data of the root node, then call the recursive function for the right subtree
    if(data > root->data){
        root->right = InsertIntoBst(root->right , data);
    }

    //if data is ledd than the data of the root node, then call the recursive function for the left subtree
    else{
        root->left = InsertIntoBst(root->left, data);
    }

    return root;
}

void take_input(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        InsertIntoBst(root, data);
        cin>>data;
    }
}

int main(){
    node* root = NULL;
    cout<<"Enter the data to be inserted in the BST"<<endl;
    take_input(root);

    if(validateBst(root) == true){
        cout<<"The given tree is a valid Binary Search Tree."<<endl;
    }
    else{
        cout<<"The given tree is not a valid Binary Search Tree."<<endl;
    }

    return 0;
}