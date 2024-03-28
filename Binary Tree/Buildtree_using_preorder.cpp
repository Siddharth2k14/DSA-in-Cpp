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

int search(int inorder[], int start, int end, int current){
    for(int i = start; i <= end; i++){
        if(inorder[i] == current){
            return i;
        }
    }
    return -1;
}

Node* BuildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;

    if(start > end){
        return NULL;
    }

    int current = preorder[idx];
    idx++;
    Node* node = new Node(current);
    if(start == end){
        return node;
    }
    int pos = search(inorder, start, end, current);
    node->left = BuildTree(preorder, inorder, start, pos-1);
    node->right = BuildTree(preorder, inorder, pos+1, end);
    return node;
}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[] = {1,2,4,5,3,6,7};
    int inorder[] = {4,2,5,1,6,3,7};

    //Building of Tree
    Node* root = BuildTree(preorder, inorder, 0, 6);
    inorderPrint(root);

    return 0;
}