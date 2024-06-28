#include<iostream>
#include<vector>
using namespace std;

int solve(int n){
    if(n <= 1)
        return 1;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += solve(i-1) * solve(n-i);
    }
    return ans;
}

int solveMem(int n, vector<int> &dp){
    if(n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += solveMem(i-1, dp) * solveMem(n-i, dp);
    }
    dp[n] = ans;
    return dp[n];
}

int solveTab(int n){
    vector<int> dp(n+1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

int numTrees(int n){
    // return solve(n);
    // vector<int> dp(n+1, -1);
    // return solveMem(n, dp);

    return solveTab(n);
}

int main(){
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    cout << "Number of BST are -> " << numTrees(n) << endl;

    return 0;
}