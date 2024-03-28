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

bool twoSum(node* root, int key){
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int i = 0, j = inorderVal.size() - 1;
    while(i < j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == key){
            return true;
        }
        else if(sum > key){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}

int main(){
    node* root = NULL;
    cout << "Enter the data to be inserted in the BST" << endl;
    take_input(root);
    
    int target;
    cout << "Enter the number" << endl;
    cin >> target;

    if(twoSum(root, target) == true){
        cout << "Value is found" << endl;
    }
    else{
        cout << "Value is not found" << endl;
    }
    
   return 0;
}