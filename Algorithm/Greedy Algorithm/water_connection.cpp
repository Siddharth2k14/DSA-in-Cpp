#include<iostream>
#include<cstring>
#include<vector>
#include<limits.h>
using namespace std;

void dfs(int node, vector<pair<int, int>> g[], int &m, int &end, int vis[]){
    vis[node] = 1;

    for(auto e : g[node]){
        if(vis[e.first] == 0){
            m = min(m, e.second);
            end = e.first;
            dfs(e.first, g, m, end, vis);
        }
    }
}

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d){
    int vis[n+1];
    vector<vector<int>> ans;
    memset(vis, 0, sizeof(vis));
    vector<int> in(n+1, 0);
    vector<int> out(n+1, 0);
    vector<pair<int, int>> g[n+1];

    for(int i = 0; i < p; i++){
        out[a[i]] = 1;
        in[b[i]] = 1;
        g[a[i]].push_back({b[i], d[i]});
    }

    for(int i = 0; i <= n; i++){
        if(in[i] == 0 && out[i] == 1 && vis[i] == 0){
            int s = i;
            int e;
            int m = INT_MAX;
            dfs(i, g, m, e, vis);
            ans.push_back({s, e, m});
        }
    }

    return ans;
}

int main(){
    int n, p;
    cin >> n >> p;
    
    vector<int> a(p), b(p), d(p);
    
    cout << "Enter the first input array here: " << endl;
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }
    
    cout << "Enter the second input array here: " << endl;
    for (int i = 0; i < p; i++) {
        cin >> b[i];
    }

    cout << "Enter the third input array here: " << endl;
    for (int i = 0; i < p; i++) {
        cin >> d[i];
    }

    vector<vector<int>> result = solve(n, p, a, b, d);
    cout << result.size() << endl;
    for (auto row : result) {
        cout << row[0] << " " << row[1] << " " << row[2] << "\n";
    }

    return 0;
}