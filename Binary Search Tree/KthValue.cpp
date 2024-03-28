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

int solve(node* root, int& i, int k){
    //base case
    if(root == NULL){
        return -1;
    }

    int left = solve(root->left, i, k);

    if(left != -1){
        return left;
    }

    i++;
    if(i == k){
        return root->data;
    }

    return solve(root->right, i, k);
}

int KthSmallest(node* root, int k){
    int ans;
    int i = 0;
    ans = solve(root, i, k);
    return ans;
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
    inorder(root);

    int k;
    cout << "Enter the value of K" << endl;
    cin >> k;

    cout << "The " << k <<"th smallest is " << KthSmallest(root, k) << endl;

    return 0;
}