#include<bits/stdc++.h>
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

node* inorderToBst(int si, int ei, vector<int> inorderVal){
    //base case
    if(si > ei){
        return NULL;
    }
    int mid = si + (ei - si)/2;
    node* root = new node(inorderVal[mid]);
    root->left = inorderToBst(si, mid-1, inorderVal);
    root->right = inorderToBst(mid+1, ei, inorderVal);

    return root;
}

node* balancedBst(node* root){
    vector<int> inorderVal;
    inorder(root, inorderVal);
    return inorderToBst(0, inorderVal.size()-1, inorderVal);
}

int main(){
    node* root = NULL;
    cout << "Enter the data to be inserted in the BST" << endl;
    take_input(root);

    cout << "Previous Level order traversal" << endl;
    LevelOrderTraversal(root);

    node* r2 = balancedBst(root);
    cout << "Next Level order traversal" << endl;
    LevelOrderTraversal(r2);

    return 0;
}