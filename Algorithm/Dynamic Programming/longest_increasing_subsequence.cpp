#include<iostream>
#include<vector>
using namespace std;

//Using Recursion
int solve(vector<int> &nums, int current, int previous){
    int n = nums.size();
    if(current == n)
        return 0;

    int include = 0;
    if(previous == -1 || nums[current] > nums[previous]){
        include = 1 + solve(nums, current+1, current);
    }
    int exclude = 0 + solve(nums, current+1, previous);

    int ans = max(include, exclude);
    return ans;
}

//Using Recurion & Memoization
int solveMem(vector<int> &nums, int current, int previous, vector<vector<int>> &dp){
    int n = nums.size();
    if(current == n)
        return 0;
    if(dp[current][previous+1] != -1)
        return dp[current][previous+1];
    int include = 0;
    if(previous == -1 || nums[current] > nums[previous]){
        include = 1 + solveMem(nums, current+1, current, dp);
    }
    int exclude = 0 + solveMem(nums, current+1, previous, dp);
    dp[current][previous+1] = max(include, exclude);
    return dp[current][previous+1];
}

//Using Tabulation
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int current = n-1; current >= 0; current--){
        for(int previous = current-1; previous >= -1; previous--){
            int include = 0;
            if(previous == -1 || nums[current] > nums[previous]){
                include = 1 + dp[current+1][current+1];
            }
            int exclude = 0 + dp[current+1][previous+1];
            dp[current][previous+1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int lengthOfLIS(vector<int> &nums){
    return solve(nums, 0, -1);

    // int n = nums.size();
    // vector<vector<int>> dp(n, vector<int> (n+1, -1));
    // return solveMem(nums, 0, -1, dp);

    return solveTab(nums);
}

int main(){
    vector<int> nums = {7,7,7,7,7,7,7};

    cout << "The length of longest increasing subsequence is -> " << lengthOfLIS(nums) << endl;

    return 0;
}