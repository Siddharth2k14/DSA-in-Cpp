#include<bits/stdc++.h>
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
    int value;
    cin>>value;
    root = new Node(value);

    if(value == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting in left "<<value<<endl;
    root->left = BuildTree(root->left);

    cout<<"Enter the data for inserting in right "<<value<<endl;
    root->right = BuildTree(root->right);

    return root;
}

vector<int> TopView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<Node*,int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    for(auto i : topNode){
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    vector<int> ans = TopView(root);
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}