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

vector<int> verticalOrder(Node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    vector<int> ans;

    //base case
    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while(!q.empty()){
        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, make_pair(hd+1,lvl+1)));
        }
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    vector<int> ans = verticalOrder(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}