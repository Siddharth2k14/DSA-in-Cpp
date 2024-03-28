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

vector<int> zigzagTraversal(Node* root){
    //base case
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i = 0; i < size; i++){
            Node* n = q.front();
            q.pop();

            int index = leftToRight ? i : (size-1-i);
            ans[index] = n->data;

            if(n->left != NULL){
                q.push(n->left);
            }
            if(n->right != NULL){
                q.push(n->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i : ans){
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    // cout<<"The Zig-Zag Traversal is "<<zigzagTraversal(root)<<endl;
    vector<int> ans = zigzagTraversal(root);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}