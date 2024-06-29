#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

//Recursion
int solve(string &a, string &b, int i, int j){
    if(i >= a.length())
        return 0;

    if(j >= b.length())
        return 0;

    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solve(a, b, i+1, j+1);
    else
        ans = max(solve(a, b, i, j+1), solve(a, b, i+1, j));
    
    return ans;
}

//Recursion + Memoization
int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
  if(i >= a.length())
    return 0;

  if(j >= b.length())
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];

  int ans = 0;
  if(a[i] == b[j]){
    ans = 1 + solveMem(a, b, i+1, j+1, dp);
  }
  else{
    ans = max(solveMem(a, b, i, j+1, dp), solveMem(a, b, i+1, j, dp));
  }

  dp[i][j] = ans;
  return dp[i][j];
}

//Tabulation
int solveTab(string &a, string &b){
  vector<vector<int>> dp(a.length()+1, vector<int> (b.length()+1, 0));

  for(int i = a.length()-1; i >= 0; i--){
    for(int j = b.length()-1; j >= 0; j--){
      int ans = 0;
      if(a[i] == b[j]){
        ans = 1 + dp[i+1][j+1];
      }
      else{
        ans = max(dp[i][j+1], dp[i+1][j]);
      }

      dp[i][j] = ans;
    }
  }

  return dp[0][0];
}

int getLengthOfLCS(string &str1, string &str2){
    // return solve(str1, str2, 0, 0);
    // vector<vector<int>> dp(str1.length()+1, vector<int> (str2.length()+1, -1));
    // return solveMem(str1, str2, 0, 0, dp);

    return solveTab(str1, str2);
}

int main(){
    string str1;
    cout << "Enter the first string here:" << endl;
    cin >> str1;

    string str2;
    cout << "Enter the second string here:" << endl;
    cin >> str2;

    cout << "The maximum length of LCS is -> " << getLengthOfLCS(str1, str2) << endl;

    return 0;
}