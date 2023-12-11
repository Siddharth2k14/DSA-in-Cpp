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

node* InsertIntoBst(node* &root, int data){
    if (root == NULL) {
        root = new node(data);
        return root;
    }

    if(data > root->data){
        root->right = InsertIntoBst(root->right, data);
    }
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

bool searching(node* root, int key){
    if(root==NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(key > root->data){
        return searching(root->right, key);
    }
    else{
        return searching(root->left, key);
    }
}

int main(){
    node* root = NULL;
    cout<<"Enter the data to be inserted in the BST"<<endl;
    take_input(root);

    int key;
    cout<<"Enter the data to be searched in BST"<<endl;
    cin>>key;

    if(searching(root, key) == true){
        cout<<"Found "<<key<<" in the tree."<<endl;
    }
    else{
        cout<<"Not Found "<<key<<" in the tree."<<endl;
    }
    return 0;
}