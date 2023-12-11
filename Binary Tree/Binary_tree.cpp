#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// N->Root
// L->Left Subtree
// R->Right Subtree

void preorder(Node* root){ //Uses NLR
    if(root == NULL){ //If root is Null then return from function
        return;
    }
    cout<<root->data<<" "; //Prints the root data
    preorder(root->left); //Traverse the left subtree
    preorder(root->right); //Traverse the right subtree
}

void inorder(Node* root){ //Uses LNR
    if(root == NULL){ //If root is Null then return from function
        return;
    }
    inorder(root->left); //Traverse the left subtree
    cout<<root->data<<" "; //Prints the root data
    inorder(root->right); //Traverse the right subtree
}

void postorder(Node* root){ //Uses LRN
    if(root == NULL){ //If root is Null then return from function
        return;
    }
    postorder(root->left); //Traverse the left subtree
    postorder(root->right); //Traverse the right subtree
    cout<<root->data<<" "; //Prints the root data
}

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

int main(){
    Node* root = NULL;
    root = BuildTree(root); //Building the Binary Tree

    // cout<<"Preorder Traversal"<<endl; //Prints the Preorder Traversal
    // preorder(root);
    
    // cout<<"Inorder Traverssl"<<endl; //Prints the Inorder Traversal
    // inorder(root);

    // cout<<"Postordre Traversal"<<endl; //Prints the Postorder Traversal
    // postorder(root);
    return 0;
}