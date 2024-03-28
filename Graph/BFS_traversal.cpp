#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void bfs(vector<vector<int>> &adj, vector<int> &ans, unordered_map<int, bool> &visited){
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i : adj[frontNode]){
            if(!visited[i])
                q.push(i);
                visited[i] = true;
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    bfs(adj, ans, visited);

    return ans;
}

int main() {
    int n = 5; // number of nodes in the graph
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 3}, {3, 4} }; // adjacency list representation of the graph

    vector<int> traversalOrder = bfsTraversal(n, adj);

    cout << "BFS Traversal Order: ";
    for(int node : traversalOrder) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}