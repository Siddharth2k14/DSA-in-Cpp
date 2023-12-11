//A Binary Tree is balanced if and only if the difference ;of the height of left subtree and the height of right subtree is not more than one.
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

//Without using pair concept

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int left = height(root->left);
    int right = height(root->right);
    
    int ans = max(left,right)+1;
    return ans;
}

bool isBalanced(Node* root){
    //base case
    if(root == NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff){
        return 1;
    }
    else{
        return false;
    }
}

//Using pair concept
/*pair<bool,int> isBalancedFast(Node* root){
    //base case
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool left_ans = left.first;
    bool right_ans = right.first;
    bool diff = abs(left.second-right.second)<=1; //Height is stored in second
    pair<bool,int> ans;
    ans.second = max(left.second,right.second)+1;
    if(left_ans && right_ans && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}

bool isBalancd(Node* root){
    return isBalancedFast(root).first;
}*/

int main(){
    Node* root = NULL;
    root = BuildTree(root);
    cout << "Is tree balanced: ";
    if (isBalanced(root)){
        cout <<"Yes";
    }
    else{
        cout <<"No";
    }
    return 0;
}