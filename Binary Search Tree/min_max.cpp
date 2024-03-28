#include<iostream>
#include<queue>
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

void LevelOrderTraversal(node* root){
    queue<node*> q; //Creating a queue
    q.push(root);   //Push the root in the queue
    q.push(NULL);   //Add null to indicate level is ended

    while(!q.empty()){ //traverse the queue
        node* temp = q.front(); //store the current node
        q.pop(); //pop the current node
        if(temp == NULL){   //indicates end of the current level
            cout<<endl;
            if(!q.empty()){ //If queue is not empty, add null to indicate next level end
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" "; // Print data of current node
            if(temp->left != NULL){ //traverse the left subtree, if it exists
                q.push(temp->left);
            }
            if(temp->right != NULL){ //traverse the right subtree, if it exists
                q.push(temp->right);
            }
        }
    }
}

void take_input(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        InsertIntoBst(root, data);
        cin>>data;
    }
}

node* minValue(node* root){
    node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* maxValue(node* root){
    node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    cout<<"Enter the data to be inserted in the BST"<<endl;
    take_input(root);

    cout<<"BST is"<<endl;
    LevelOrderTraversal(root);

    cout<<"Minimum value is "<<minValue(root)->data<<endl;
    cout<<"Maximum value is "<<maxValue(root)->data<<endl;

    cout<<endl<<"The inorder sequence is "<<endl;
    inorder(root);

    return 0;
}