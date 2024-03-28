#include<iostream>
#include<vector>
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

void inorder(node* root, vector<int> &in){
    if(root == NULL){
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

node* flattenBst(node* root){
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int n = inorderVal.size();

    node* newNode = new node(inorderVal[0]);
    node* current = newNode;

    for(int i = 1; i < n; i++){
        node* temp = new node(inorderVal[i]);
        current->left = NULL;
        current->right = temp;
        current = temp;
    }

    current->left = NULL;
    current->right = NULL;

    return newNode;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
}

int main(){
    node* root = NULL;
    cout << "Enter the data to be inserted in the BST" << endl;
    take_input(root);

    node* r1 = flattenBst(root);
    display(r1);

   return 0;
}