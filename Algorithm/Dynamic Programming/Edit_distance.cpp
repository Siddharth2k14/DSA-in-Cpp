#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//Recursion
int solve(string &a, string &b, int i, int j){
    if(i == a.length())
        return b.length() - j;
    if(j == b.length())
        return a.length() - i;

    int ans = 0;
    if(a[i] == b[j]){
        return solve(a, b, i+1, j+1);
    }
    else{
        //Insertion
        int insertAns = 1 + solve(a, b, i, j+1);

        //Deletion
        int deleteAns = 1 + solve(a, b, i+1, j);

        //Replace
        int replaceAns = 1 + solve(a, b, i+1, j+1);

        ans = min(insertAns, min(deleteAns, replaceAns));
    }

    return ans;
}

int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    if(i == a.length())
        return b.length() - j;
    if(j == b.length())
        return a.length() - i;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if(a[i] == b[j])
        return solveMem(a, b, i+1, j+1, dp);
    else{
        //Insertion
        int insertAns = 1 + solveMem(a, b, i, j+1, dp);
        //Deletion
        int deleteAns = 1 + solveMem(a, b, i+1, j, dp);
        //Replace
        int replaceAns = 1 + solveMem(a, b, i+1, j+1, dp);
        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(string &a, string &b){
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for(int j = 0; j < m; j++){
        dp[n][j] = m - j;
    }
    for(int i = 0; i < n; i++){
        dp[i][m] = n - i;
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = dp[i+1][j+1];
            else{
                //Insertion
                int insertAns = 1 + dp[i][j+1];
                //Deletion
                int deleteAns = 1 + dp[i+1][j];
                //Replace
                int replaceAns = 1 + dp[i+1][j+1];
                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}

int minDistance(string word1, string word2){
    // return solve(word1, word2, 0, 0);
    // int n = word1.length();
    // int m = word2.length();

    // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // return solveMem(word1, word2, 0, 0, dp);
    
    return solveTab(word1, word2);
}

int main(){
    string word1 = "horse";
    string word2 = "ros";

    cout << "The minimum operations required to convert the given two string are -> " << minDistance(word1, word2) << endl;
    return 0;
}