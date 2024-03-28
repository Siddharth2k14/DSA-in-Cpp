#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

public:
    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }    
};

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
    cin >> data;
    
    while(data != -1){
        root = InsertIntoBst(root, data);
        cin >> data;
    }
}

node* lca(node* root, int n1, int n2){
    //base case
    if(root == NULL){
        return NULL;
    }

    if(root->data > n1 && root->data > n2){
        return lca(root->left, n1, n2);
    }
    else if(root->data < n1 && root->data < n2){
        return lca(root->right, n1, n2);
    }
    return root;
}

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    cout << "Enter the data to be inserted in the Bst" << endl;
    take_input(root);

    int n1, n2;
    cout << "Enter the two data to find their lowest common ancestor" << endl;
    cin >> n1 >> n2;

    node* lowestCommonAncestor = lca(root, n1, n2);

    cout << "The LCA is " << lowestCommonAncestor->data << endl;

    return 0;
}