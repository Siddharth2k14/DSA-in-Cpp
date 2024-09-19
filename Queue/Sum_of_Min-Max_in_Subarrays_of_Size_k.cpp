#include<iostream>
#include<queue>
#include<vector>
using namespace std;

long long sumOfMaxAndMin(vector<int> &arr, int n, int k){
    deque<int> maxi(k);
    deque<int> mini(k);

    for(int i = 0; i < k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    long long ans = 0;
    for(int i = k; i < n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];
        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

        while(!mini.empty() && i - mini.front() >= k){
            mini.pop_back();
        }

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}

int main(){
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int n = arr.size();
    int k = 4;

    cout << "The answer is " << sumOfMaxAndMin(arr, n, k) << endl;

    return 0;
}