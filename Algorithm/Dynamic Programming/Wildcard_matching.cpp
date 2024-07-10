#include<iostream>
#include<vector>
using namespace std;

bool solve(string &str, string &pattern, int i, int j){
    int n = str.length();
    int m = pattern.length();    
    if(i > n && j > m){
        return true;
    }

    if(i <= n && j > m){
        for(int k = 0; k <= j; k++){
            if(pattern[k] != '*'){
                return false;
            }
        }
        return true;
    }

    if(i > n && j <= m){
        return false;
    }    
    
    //match
    if(str[i] == pattern[j] || pattern[j] == '?'){
        return solve(str, pattern, i+1, j+1);
    }
    else if(pattern[j] == '*'){
        return (solve(str, pattern, i, j+1) || solve(str, pattern, i+1, j));
    }
    else{
        return false;
    }
}

bool solveTab(string str, string pattern){
    int n = str.length();
    int m = pattern.length();
    vector<vector<bool>> dp(n+2, vector<bool> (m+2, false));
    dp[n][m] = true;

    for (int j = m - 1; j >= 0; j--) {
        if (pattern[j] == '*') {
            dp[n][j] = dp[n][j + 1];
        } else {
            break;
        }
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(str[i] == pattern[j] || pattern[j] == '?'){
                dp[i][j] = dp[i+1][j+1];
            }
            else if(pattern[j] == '*'){
                dp[i][j] = (dp[i][j+1] || dp[i+1][j]);
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}

bool isMatch(string s, string p) {
    return solve(s, p, 0, 0);
    // return solveTab(s, p);
}

int main(){
    string s = "cb";
    string p = "?a";

    cout << isMatch(s, p) << endl;
    return 0;
}