#include<iostream>
#include<queue>
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
    cout<<"Enter the data for the Node: "<<endl;
    int data;
    cin>>data;
    root = new Node(data); //Creating the new node with data

    if(data == -1){
        return NULL;
    }
    cout<<"Enter the data for inserting in left "<<data<<endl;
    //Traverse the left subtree
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting in right "<<data<<endl;
    //Traverse the right subtree
    root->right = BuildTree(root->right);
    return root;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q; //Creating a queue
    q.push(root);   //Push the root in the queue
    q.push(NULL);   //Add null to indicate level is ended

    while(!q.empty()){ //traverse the queue
        Node* temp = q.front(); //store the current node
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

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    LevelOrderTraversal(root);
    return 0;
}