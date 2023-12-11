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

bool Identical(Node* r1, Node* r2){
    //base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }
    if(r1 == NULL && r2 != NULL){
        return false;
    }
    if(r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = Identical(r1->left, r2->left);
    bool right = Identical(r1->right, r2->right);
    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root1 = NULL;
    root1 = BuildTree(root1);

    Node* root2 = NULL;
    root2 = BuildTree(root2);
    if(Identical(root1, root2) == 1){
        cout<<"Both Trees are identical."<<endl;
    }
    else{
        cout<<"Trees not identical"<<endl;
    }
    return 0;
}