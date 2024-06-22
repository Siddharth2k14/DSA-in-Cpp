#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check(vector<int> &box, vector<int> &nextBox){
    if(nextBox[0] < box[0] && nextBox[1] < box[1]){
        return true;
    }
    return false;
}

int solveMem(vector<vector<int>> &a, int current, int previous, vector<vector<int>> &dp){
    int n = a.size();
    if(current == n)
        return 0;

    if(dp[current][previous+1] != -1)
        return dp[current][previous+1];

    int include = 0;
    if(previous == -1 || check(a[current], a[previous])){
        include = a[current][2] + solveMem(a, current+1, current, dp);
    }
    int exclude = 0 + solveMem(a, current+1, previous, dp);

    dp[current][previous+1] = max(include, exclude);
    return dp[current][previous+1];
}

int solveTab(vector<vector<int>> &a, int n){
    vector<vector<int>> dp(6*n+1, vector<int> (6*n+1, 0));
    for(int current = a.size()-1; current >= 0; current--){
        for(int previous = current-1; previous >= -1; previous--){
            int include = 0;
            if(previous == -1 || check(a[current], a[previous])){
                include = a[current][2] + dp[current+1][current+1];
            }
            int exclude = 0 + dp[current+1][previous+1];
            dp[current][previous+1] = max(include, exclude);
        }
    }
    return dp[0][-1+1];
}

int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length, int n){
    vector<vector<int>> cuboids;
    for(int i = 0; i < n; i++){
        cuboids.push_back({width[i],height[i],length[i]});
        cuboids.push_back({length[i],width[i],height[i]});
        cuboids.push_back({length[i],height[i],width[i]});
        cuboids.push_back({width[i],length[i],height[i]});
        cuboids.push_back({height[i],length[i],width[i]});
        cuboids.push_back({height[i],width[i],length[i]});
    }

    sort(cuboids.begin(), cuboids.end());
    vector<vector<int>> dp(6*n, vector<int> (6*n+1, -1));
    return solveMem(cuboids, 0, -1, dp);
}

int main(){
    int n;
    cout << "Enter the size of the array of height, width, length" << endl;
    cin >> n;

    vector<int> height(n+1), width(n+1), length(n+1);
    cout << "Enter the height array here" << endl;
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    cout << "Enter the width array here" << endl;
    for(int i = 0; i < n; i++){
        cin >> width[i];
    }

    cout << "Enter the length array here" << endl;
    for(int i = 0; i < n; i++){
        cin >> length[i];
    }

    cout << maxHeight(height, width, length, n);
    return 0;
}