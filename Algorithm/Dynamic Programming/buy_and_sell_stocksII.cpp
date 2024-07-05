#include<iostream>
#include<vector>
using namespace std;

int solve(int index, bool buy, vector<int> &prices){
    if(index == prices.size()){
        return 0;
    }

    int profit = 0;
    if(buy == true){
        int case1 = -prices[index] + solve(index+1, 0, prices);
        int case2 = 0 + solve(index+1, 1, prices);
        profit = max(case1, case2);
    }

    else{ // buy != true
        int case3 = prices[index] + solve(index+1, 1, prices);
        int case4 = 0 + solve(index+1, 0, prices);
        profit = max(case3, case4);
    }

    return profit;
}

int maxProfit(vector<int> &prices){
    bool buy = 1;
    return solve(0, buy, prices);
}

int main(){
    vector<int> prices = {1,2,3,4,5};
    cout << "Maximum profit is -> " << maxProfit(prices) << endl;
    return 0;
}