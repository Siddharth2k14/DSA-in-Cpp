#include<iostream>
#include<vector>
using namespace std;

//Recursion
int solve(int index, bool buy, vector<int> &prices, int limit){
    if(index == prices.size())
        return 0;

    if(limit == 0)
        return 0;

    int profit = 0;
    if(buy == true){
        int case1 = -prices[index] + solve(index+1, 0, prices, limit);
        int case2 = 0 + solve(index+1, 1, prices, limit);
        profit = max(case1, case2);
    }
    else{
        int case3 = +prices[index] + solve(index+1, 1, prices, limit-1);
        int case4 = 0 + solve(index+1, 0, prices, limit);
        profit = max(case3, case4);
    }

    return profit;
}

int solveMem(int index, bool buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp){
    if(index == prices.size())
        return 0;

    if(limit == 0)
        return 0;

    if(dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    if(buy == true){
        int case1 = -prices[index] + solveMem(index+1, 0, prices, limit, dp);
        int case2 = 0 + solveMem(index+1, 1, prices, limit, dp);
        profit = max(case1, case2);
    }
    else{
        int case3 = +prices[index] + solveMem(index+1, 1, prices, limit-1, dp);
        int case4 = 0 + solveMem(index+1, 0, prices, limit, dp);
        profit = max(case3, case4);
    }

    dp[index][buy][limit] = profit;
    return dp[index][buy][limit];
}

int solveTab(vector<int> &prices, int k){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
    for(int index = n-1; index >= 0; index--){
        for(int limit = 0; limit < 2*k; limit++){
            int profit = 0;
            if(limit % 2 == 0){
                int case1 = -prices[index] + dp[index+1][limit+1];
                int case2 = 0 + dp[index+1][limit];
                profit = max(case1, case2);
            }
            else{
                int case3 = +prices[index] + dp[index+1][limit+1];
                int case4 = 0 + dp[index+1][limit];
                profit = max(case3, case4);
            }
            dp[index][limit] = profit;
        }
    }
    return dp[0][0];
}

int maxProfit(vector<int> &prices, int k){
    // return solve(0, 1, prices, k);

    // int n = prices.size();
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    // return solveMem(0, 1, prices, k, dp);

    return solveTab(prices, k);
}

int main(){
    vector<int> prices = {2,4,1};
    int k = 2;
    cout << "Maximum profit is -> " << maxProfit(prices, k) << endl;
    return 0;
}