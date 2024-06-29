#include<bits/stdc++.h>
using namespace std;

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

int longestPalindromeSubsequence(string s)
{
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    int ans = solveTab(s, revStr);
    return ans;
}

int main(){
    string s1;
    cout << "Enter the string here" << endl;
    cin >> s1;

    cout << longestPalindromeSubsequence(s1) << endl;

    return 0;
}