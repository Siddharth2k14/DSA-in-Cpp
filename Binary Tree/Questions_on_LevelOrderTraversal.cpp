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

int sumAtK(Node* root, int K){
    if(root == NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp != NULL){
            if(level == K){
                sum = sum + temp->data;
            }
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
        else{
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
                level = level + 1;
            }
        }
    }

    return sum;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    int k;
    cout<<"Enter the value of k here:"<<endl;
    cin>>k;
    cout<<"The sum at "<<k<<"Node is "<<sumAtK(root,k)<<endl;
    return 0;
}