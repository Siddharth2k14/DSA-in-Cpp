#include<iostream>
#include<queue>
using namespace std;

long long mincost(long long arr[], long long n){
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0; i < n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;
    while(pq.size() > 1){
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        long long mergedLength = first + second;
        cost = cost + mergedLength;

        pq.push(mergedLength);
    }

    return cost;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Compute the minimum cost of merging all intervals
    long long min_cost = mincost(arr, n);

    // Print the minimum cost
    cout << "Minimum cost of merging all intervals: " << min_cost << endl;

    return 0;
}