#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] == rank[v]){
        parent[v] = u;
        rank[u]++;
    }
    else if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
    }
}

int mst(vector<vector<int>> &edges, int n){
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;
    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            minWeight += wt;
            UnionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the graph: ";
    cin >> n;

    vector<vector<int>> edges(n-1);
    cout << "Enter the edges in the format 'u v wt' (u, v are nodes, wt is weight):\n";
    for(int i=0; i<n-1; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int result = mst(edges, n);
    
    cout << "Minimum Spanning Tree weight: " << result << endl;

    return 0;
}