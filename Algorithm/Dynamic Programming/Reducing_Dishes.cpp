#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Using Recursion
int solve(vector<int> &satisfaction, int index, int time){
    if(index == satisfaction.size())
        return 0;

    int include = satisfaction[index] * (time+1) + solve(satisfaction, index+1, time+1);
    int exclude = 0 + solve(satisfaction, index+1, time);

    int ans = max(include, exclude);
    return ans;
}

//Using Recursion + Memoization
int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
    if(index == satisfaction.size())
        return 0;

    if(dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time+1) + solveMem(satisfaction, index+1, time+1, dp);
    int exclude = 0 + solveMem(satisfaction, index+1, time, dp);

    dp[index][time] = max(include, exclude);
    return dp[index][time];
}

//Using Tabulation
int solveTab(vector<int> &satisfaction){
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    dp[1][n] = 0;

    for(int index = n-1; index >= 0; index--){
        for(int time = index; time >= 0; time--){
            int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
            int exclude = 0 + dp[index+1][time];

            dp[index][time] = max(include, exclude);
        }
    }

    return dp[0][0];
}

int maxSatisfaction(vector<int> &satisfaction){
    // sort(satisfaction.begin(), satisfaction.end());
    // return solve(satisfaction, 0, 0);

    // int n = satisfaction.size();
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // sort(satisfaction.begin(), satisfaction.end());
    // return solveMem(satisfaction, 0, 0, dp);

    sort(satisfaction.begin(), satisfaction.end());
    return solveTab(satisfaction);
}

int main(){
    vector<int> satisfaction = {4,3,2};

    cout << maxSatisfaction(satisfaction) << endl;
    return 0;
}