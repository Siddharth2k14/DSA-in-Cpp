#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Using Recursion
int solve(vector<int> &v, int i, int j){
    if(i+1 == j){
        return 0;
    }

    int ans = INT_MAX;
    for(int k = i+1; k < j; k++){
        ans = min(ans, (v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j)));
    }
    return ans;
}

//Using Memoization
int solveMem(vector<int> &v, int i, int j, vector<vector<int>> &dp){
    if(i+1 == j){
        return 0;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k = i+1; k < j; k++){
        ans = min(ans, (v[i] * v[j] * v[k] + solveMem(v, i, k, dp) + solveMem(v, k, j, dp)));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

//Using Tabulation
int solveTab(vector<int> &v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for(int i = n-1; i >= 0; i--){
        for(int j = i+2; j < n; j++){
            int ans = INT_MAX;
            for(int k = i+1; k < j; k++){
                ans = min(ans, (v[i]*v[j]*v[k] + dp[i][k] + dp[k][j]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}    

int minScoreTriangulation(vector<int> &values){
    return solve(values, 0, values.size()-1);

    // int n = values.size();
    // vector<vector<int>> dp(n, vector<int> (n, -1));

    // return solveTab(values);
}

int main(){
    int n;
    cout << "Enter the number of vertices in the given figure" << endl;
    cin >> n;

    vector<int> values(n+1);
    cout << "Enter the values in the array" << endl;
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }

    cout << "Thee possible smallest score is -> " << minScoreTriangulation(values) << endl;

    return 0;
}