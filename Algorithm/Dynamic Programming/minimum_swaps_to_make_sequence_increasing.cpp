#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped){
    if(index == nums1.size())
        return 0;

    int ans = INT_MAX;

    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];

    if(swapped){
        swap(prev1, prev2);
    }

    //No Swap
    if(nums1[index] > prev1 && nums2[index] > prev2){
        ans = solve(nums1, nums2, index+1, 0);
    }

    //Swap
    if(nums1[index] > prev2 && nums2[index] > prev1){
        ans = min(ans, 1 + solve(nums1, nums2, index+1, 1));
    }
    return ans;
}

int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp){
    if(index == nums1.size())
        return 0;
    if(dp[index][swapped] != -1)
        return dp[index][swapped];
    int ans = INT_MAX;
    int prev1 = nums1[index-1];
    int prev2 = nums2[index-1];
    if(swapped == true)
        swap(prev1, prev2);
    
    //No Swap
    if(nums1[index] > prev1 && nums2[index] > prev2){
        ans = solveMem(nums1, nums2, index+1, 0, dp);
    }
    //Swap
    if(nums1[index] > prev2 && nums2[index] > prev1){
        ans = min(ans, 1+solveMem(nums1, nums2, index+1, 1, dp));
    }
    dp[index][swapped] = ans;
    return dp[index][swapped];
}

int solveTab(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size();
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    for(int index = n-1; index >= 1; index--){
        for(int swapped = 1; swapped >= 0; swapped--){
            int ans = INT_MAX;
            int prev1 = nums1[index-1];
            int prev2 = nums2[index-1];
            if(swapped == true)
                swap(prev1, prev2);
            //No Swap
            if(nums1[index] > prev1 && nums2[index] > prev2){
                ans = dp[index+1][0];
            }
            //Swap
            if(nums1[index] > prev2 && nums2[index] > prev1){
                ans = min(ans, 1 + dp[index+1][1]);
            }
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

int minSwaps(vector<int> &nums1, vector<int> &nums2){
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    // bool swapped = 0;
    // return solve(nums1, nums2, 1, swapped);

    // vector<vector<int>> dp(nums1.size(), vector<int> (2, -1));
    // bool swapped = 0;
    // return solveMem(nums1, nums2, 1, swapped, dp);

    return solveTab(nums1, nums2);
}

int main(){
    vector<int> nums1 = {1,3,5,4};
    vector<int> nums2 = {1,2,3,7};

    cout << minSwaps(nums1, nums2) << endl;

    return 0;
}