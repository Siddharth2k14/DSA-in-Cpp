#include<iostream>
#include<vector>
using namespace std;

bool solve(int index, int n, vector<int> &arr, int target){
    if(index >= n)
        return 0;
    
    if(target < 0)
        return 0;
    
    if(target == 0)
        return 1;
        
    bool include = solve(index+1, n, arr, target - arr[index]);
    bool exclude = solve(index+1, n, arr, target - 0);
    
    return include or exclude;
}

bool solveMem(int index, int n, vector<int> &arr, int target, vector<vector<int>> &dp){
    if(index >= n)
        return 0;
    
    if(target < 0)
        return 0;
    
    if(target == 0)
        return 1;
        
    if(dp[index][target] != -1)
        return dp[index][target];
        
    bool include = solveMem(index+1, n, arr, target - arr[index], dp);
    bool exclude = solveMem(index+1, n, arr, target - 0, dp);
    
    dp[index][target] = include or exclude;
    
    return dp[index][target];
}

bool solveTab(int n, vector<int> &arr, int total){
    vector<vector<int>> dp(n+1, vector<int> (total+1, 0));
    
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
    
    for(int index = n-1; index >= 0; index--){
        for(int target = 0; target <= total/2; target++){
            
            bool include = 0;
            if(target - arr[index] >= 0)
                include = dp[index+1][target-arr[index]];
            bool exclude = dp[index+1][target-0];
            dp[index][target] = include or exclude;
        }
    }
    return dp[0][total/2];
}
int equalPartition(int N, vector<int> &arr){
    int total = 0;
    for(int i = 0; i < N; i++){
        total += arr[i];
    }
    
    if(total & 1){
        return 0;
    }
    
    int target = total / 2;
    
    // return solve(0, N, arr, target);
    
    // vector<vector<int>> dp(N, vector<int> (target+1, -1));
    // return solveMem(0, N, arr, target, dp);
    
    return solveTab(N, arr, total);
}

int main(){
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;

    vector<int> arr(n+1);
    cout << "Enter the elements here" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr.at(i);
    }

    cout << equalPartition(n, arr) << endl;

    return 0;
}