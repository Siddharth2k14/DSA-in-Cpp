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
    cout<<"Enter the data for the node:"<<endl;
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

void flatten(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){
            Node* pred = curr->left;
            while(pred->right != NULL){
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void printFlattenedTree(Node* root) {
    Node* curr = root;
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root); // Building the tree

    flatten(root); // Flattening the binary tree
    
    cout << "The flattened tree is: " << endl;
    printFlattenedTree(root); // Printing the flattened tree

    return 0;
}