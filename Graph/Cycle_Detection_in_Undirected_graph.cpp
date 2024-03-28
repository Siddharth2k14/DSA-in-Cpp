#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

bool isCyclic(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    unordered_map<int, int> parent;
    parent[src] = -1;
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && (neighbour != parent[front])){
                return true;
            }

            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclic(i, visited, adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int n, m;

    // Get the user inputs
    cout << "Enter the number of nodes and the number of edges separated by a space: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2, 0));
    cout << "Enter the " << m << " edges (u and v separated by a space):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string result = cycleDetection(edges, n, m);
    cout << result << endl;

    return 0;
}