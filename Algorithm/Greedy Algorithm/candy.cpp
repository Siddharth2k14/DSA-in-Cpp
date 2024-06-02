#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> CandyStore(int candy[], int n, int k){
    sort(candy, candy+n);
    int mini = 0;
    int buy = 0;
    int free = n-1;

    while(buy <= free){
        mini = mini + candy[buy];
        buy = buy + 1;
        free = free - k;
    }

    int maxi = 0;
    buy = n-1;
    free = 0;

    while(free <= buy){
        maxi = maxi + candy[buy];
        buy = buy - 1;
        free = free + k;
    }

    vector<int> ans;
    ans.push_back(mini);
    ans.push_back(maxi);
    return ans;
}

int main(){
    int n;
    cout << "Enter the number of candies here" << endl;
    cin >> n;

    int k;
    cout << "Enter the value of k here" << endl;
    cin >> k;

    int candies[n];
    cout << "Enter the candies here" << endl;
    for(int i = 0; i < n; i++){
        cin >> candies[i];
    }

    vector<int> ans = CandyStore(candies, n, k);
    cout << "Minimum cost -> " << ans[0] << endl;
    cout << "Maximum cost -> " << ans[1] << endl;
    return 0;
}