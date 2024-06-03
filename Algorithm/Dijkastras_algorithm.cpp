#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> Dijkstaras(vector<vector<int>> &vec, int vertices, int edges, int source){
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> dist(vertices);

    for(int i = 0; i < vertices; i++){
        dist[i] = INT_MAX;
    }

    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty()){
        auto top = *(st.begin());
        
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record != st.end()){
                    st.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    return dist;
}

int main() {
    int vertices, edges;
    int source;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the source vertex: ";
    cin >> source;

    vector<vector<int>> graph(edges, vector<int>(3));

    for(int i = 0; i < edges; i++){
        cout << "Enter the vertices and weight of edge " << i+1 << ": ";
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    vector<int> distances = Dijkstaras(graph, vertices, edges, source);

    cout << "Distances from source " << source << ":" << endl;
    for(int i = 0; i < vertices; i++){
        cout << "Vertex " << i << ": " << (distances[i] == INT_MAX ? "INF" : to_string(distances[i])) << endl;
    }

    return 0;
}