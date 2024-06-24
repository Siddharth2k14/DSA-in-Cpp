#include<iostream>
#include<vector>
using namespace std;

//Using Recursion
long long solve(int dices, int faces, int target){
    if(target < 0)
        return 0;
    if(dices == 0 && target != 0)
        return 0;
    if(dices != 0 && target == 0)
        return 0;
    if(dices == 0 && target == 0)
        return 1;

    long long ans = 0;
    for(int i = 1; i <= faces; i++){
        ans = ans + solve(dices-1, faces, target-i);
    }
    return ans;
}

//Uding Recursion && Tabulation
long long solveMem(int dices, int faces, int target, vector<vector<long long>> &dp){
    if(target < 0)
        return 0;
    if(dices == 0 && target != 0)
        return 0;
    if(dices != 0 && target == 0)
        return 0;
    if(dices == 0 && target == 0)
        return 1;

    if(dp[dices][target] != -1)
        return dp[dices][target];

    long long ans = 0;
    for(int i = 1; i <= faces; i++){
        ans = ans + solveMem(dices-1, faces, target-i, dp);
    }
    dp[dices][target] = ans;
    return dp[dices][target];
}

//Using Tabulation
long long solveTab(int d, int f, int t){
    vector<vector<long long>> dp(d+1, vector<long long> (t+1, 0));
    dp[0][0] = 1;
    
    for(int dice = 1; dice <= d; dice++){
        for(int target = 1; target <= t; target++){
            long long ans = 0;
            for(int i = 1; i <= f; i++){
                if(target-i >= 0)
                    ans = ans + dp[dice - 1][target - i];
            }
            dp[dice][target] = ans;
        }
    }
    return dp[d][t];
}

long long noofways(int n, int m, int t){
    // return solve(n, m, t);

    // vector<vector<long long>> dp(n+1, vector<long long> (t+1, -1));
    // return solveMem(n, m, t, dp);

    return solveTab(n, m, t);
}

int main(){
    int n;
    cout << "Enter the number of dices" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of faces" << endl;
    cin >> m;

    int t;
    cout << "Enter the target sum" << endl;
    cin >> t;

    cout << "Total number of ways are -> " << noofways(n, m, t) << endl;

    return 0;
}