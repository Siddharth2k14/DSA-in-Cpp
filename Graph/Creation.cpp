#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool Direction){
        adj[u].push_back(v);

        if(Direction == 0){
            adj[v].push_back(u);
        }
    }

    void print(){
        for(auto i : adj){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int n;
    cout << "Enter the number of nodes here:" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges here:" << endl;
    cin >> m;

    graph g;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }

    g.print();

    return 0;
}