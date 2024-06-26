#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int longestSubsequence(vector<int> &arr, int difference){
    unordered_map<int, int> dp;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++){
        int temp = arr[i] - difference;
        int tempAns = 0;

        if(dp.count(temp))
            tempAns = dp[temp];

        dp[arr[i]] = 1 + tempAns;

        ans = max(ans, dp[arr[i]]);
    }

    return ans;
}

int main(){
    vector<int> arr = {1,5,7,8,5,3,4,2,1};
    int difference = -2;

    cout << longestSubsequence(arr, difference) << endl;
    return 0;
}