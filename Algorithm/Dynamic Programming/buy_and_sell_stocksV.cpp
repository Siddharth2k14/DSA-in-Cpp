#include<iostream>
#include<vector>
using namespace std;

int solve(int index, bool buy, vector<int> &prices, int fee){
    if(index == prices.size())
        return 0;
    int profit = 0;
    if(buy == true){
        int case1 = -prices[index] + solve(index+1, 0, prices, fee);
        int case2 = 0 + solve(index+1, 1, prices, fee);
        profit = max(case1, case2);
    }
    else{
        int case3 = +prices[index] + solve(index+1, 1, prices, fee)-fee;
        int case4 = 0 + solve(index+1, 0, prices, fee);
        profit = max(case3, case4);
    }
    return profit;
}

int solveMem(int index, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp){
    if(index == prices.size())
        return 0;
    if(dp[index][buy] != -1)
        return dp[index][buy];
    int profit = 0;
    if(buy == true){
        int case1 = -prices[index] + solveMem(index+1, 0, prices, fee, dp);
        int case2 = 0 + solveMem(index+1, 1, prices, fee, dp);
        profit = max(case1, case2);
    }
    else{
        int case3 = +prices[index] + solveMem(index+1, 1, prices, fee, dp)-fee;
        int case4 = 0 + solveMem(index+1, 0, prices, fee, dp);
        profit = max(case3, case4);
    }
    dp[index][buy] = profit;
    return dp[index][buy];
}

int solveTab(vector<int> &prices, int fee){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    for(int index = n-1; index >= 0; index--){
        for(int buy = 1; buy >= 0; buy--){
            int profit = 0;
            if(buy == true){
                int case1 = -prices[index] + dp[index+1][0];
                int case2 = 0 + dp[index+1][1];
                profit = max(case1, case2);
            }
            else{
                int case3 = +prices[index] + dp[index+1][1]-fee;
                int case4 = 0 + dp[index+1][0];
                profit = max(case3, case4);
            }
            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}

int maxProfit(vector<int>& prices, int fee) {
    bool buy = 1;
    // return solve(0, buy, prices, fee);
    // vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
    // return solveMem(0, buy, prices, fee, dp);
    return solveTab(prices, fee);
}

int main(){
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << "Maximum profit is -> " << maxProfit(prices, fee) << endl;
    return 0;
}