#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void dfs(unordered_map<int, list<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited, int node){
    ans.push_back(node);
    visited[node] = true;

    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(adj, ans, visited, i);
        }
    }
}

vector<int> dfs_traversal(int v, unordered_map<int, list<int>> adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    for(int i = 0; i < v; i++){
        if(!visited[i])
            dfs(adj, ans, visited, i);
    }

    return ans;
}

int main(){

    return 0;
}