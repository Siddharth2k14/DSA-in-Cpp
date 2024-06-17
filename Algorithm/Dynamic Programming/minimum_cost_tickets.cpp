#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

//Using Recursion
int solve(vector<int> &days, vector<int> &costs, int index){
    int n = days.size();
    if(index >= n)
        return 0;

    //1 day pass
    int option1 = costs[0] + solve(days, costs, index+1);

    //7 days pass
    int i;
    for(i = index; i < n && days[i] < days[index]+7; i++);
    int option2 = costs[1] + solve(days, costs, i);

    //30 days pass
    for(i = index; i < n && days[i] < days[index]+30; i++);
    int option3 = costs[2] + solve(days, costs, i);

    return min(option1, min(option2, option3));
}

//Using Recursion & Memoization
int solveMem(vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
    int n = days.size();
    if(index >= n)
        return 0;
    if(dp[index] != -1)
        return dp[index];
    //1 day pass
    int option1 = costs[0] + solveMem(days, costs, index+1, dp);
    //7 days pass
    int i;
    int option2;
    for(i = index; i < n && days[i] < days[index]+7; i++);
    option2 = costs[1] + solveMem(days, costs, i, dp);
    //30 days pass
    int option3;
    for(i = index; i < n && days[i] < days[index]+30; i++);
    option3 = costs[2] + solveMem (days, costs, i, dp);
    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}    

//Using Tabulation
int solveTab(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;
    for(int k = n-1; k >= 0; k--){
        //1 day pass
        int option1 = costs[0] + dp[k+1];
        //7 days pass
        int i;
        int option2;
        for(i = k; i < n && days[i] < days[k]+7; i++);
        option2 = costs[1] + dp[i];
        //30 days pass
        int option3;
        for(i = k; i < n && days[i] < days[k]+30; i++);
        option3 = costs[2] + dp[i];
        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int mincostTickets(vector<int> &days, vector<int> &costs){
    return solve(days, costs, 0);
}

int main(){
    int n, m;
    cout << "Enter the number of elements in the days array as n" << endl;
    cin >> n;

    cout << "Enter the number of elements in the costs array as m" << endl;
    cin >> m;

    vector<int> days(n+1);
    vector<int> costs(m+1);

    cout << "Enter the days array here" << endl;
    for(int i = 0; i < n; i++){
        cin >> days[i];
    }

    cout << "Enter the costs array here" << endl;
    for(int i = 0; i < m; i++){
        cin >> costs[i];
    }

    cout << "The minimum cost of the tickets is -> " << mincostTickets(days, costs) << endl;
    return 0;
}