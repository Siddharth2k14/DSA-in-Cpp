#include<iostream>
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

node* insertIntoBst(node* &root, int value){
    //base case
    if(root == NULL){
        root = new node(value);
        return root;
    }

    if(root->data > value){
        root->left = insertIntoBst(root->left, value);
    }
    else{
        root->right = insertIntoBst(root->right, value);
    }

    return root;
}

void take_input(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBst(root, data);
        cin>>data;
    }
}

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

pair<int, int> pred_succ(node* root, int key){
    node* temp = root;
    int pred = -1;
    int succ = -1;

    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
        else{
            pred = temp->data;
            temp = temp->right;
        }
    }

    // pred
    node* leftTree = temp->left;
    while(leftTree != NULL){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    //succ
    node* rightTree = temp->right;
    while(rightTree != NULL){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

int main(){
    node* root = NULL;
    cout<<"Enter the data to be inserted in the BST"<<endl;
    take_input(root);

    cout<<"The Bst is "<<endl;
    inorder(root);

    int key;
    cout<<"Enter the key whose you want to find the predecessor and successor "<<endl;
    cin>>key;

    cout<<"The predecessor of the "<<key<<" is "<<pred_succ(root, key).first<< " and the successor is "<<pred_succ(root, key).second<<endl;

    return 0;
}