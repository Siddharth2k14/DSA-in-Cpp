#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> mat){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && mat[x][y] == 1){
        return  true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> mat, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 ways
    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, n, visited, mat)){
        solve(mat, n, ans, newx, newy, visited, path + 'D');
    }

    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, n, visited, mat)){
        solve(mat, n, ans, newx, newy, visited, path + 'L');
    }

    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, n, visited, mat)){
        solve(mat, n, ans, newx, newy, visited, path + 'R');
    }

    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, n, visited, mat)){
        solve(mat, n, ans, newx, newy, visited, path + 'U');
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();
    vector<string> ans;
    if(mat[0][0] == 0){
        return ans;
    }

    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited = mat;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] == 0;
        }
    }

    string path = "";
    solve(mat, n, ans, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = findPath(mat);

    for(const string &s : result) {
        cout << s << " ";
    }

    return 0;
}