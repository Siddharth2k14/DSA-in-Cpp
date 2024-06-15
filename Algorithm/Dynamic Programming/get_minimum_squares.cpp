#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(int n){
    if(n == 0)
	    return 0;
	    
	int ans = n;
	for(int i = 1; i*i <= n; i++){
	    ans = min(ans, 1+solve(n-i*i));
	}
	    return ans;
}
	
int solveMem(int n, vector<int> &dp){
   if(n == 0)
    return 0;
   
   if(dp[n] != -1)
    return dp[n];
   
   int ans = n;
   for(int i = 1; i*i <= n; i++){
       ans = min(ans, 1+solveMem(n-i*i, dp));
   }
   
   dp[n] = ans;
   return dp[n];
}
	
int solveTab(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= n; j++){
            if(i-j*j >= 0){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
    }
    
    return dp[n];
}
	
	int MinSquares(int n)
	{
	   // return solve(n);
	   //vector<int> dp(n+1, -1);
	   //return solveMem(n, dp);
	   return solveTab(n);
	}

int main(){
    int n;
    cout << "Enter the number here:" << endl;
    cin >> n;

    cout << MinSquares(n) << endl;

    return 0;
}