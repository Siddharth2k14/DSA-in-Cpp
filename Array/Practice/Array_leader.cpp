#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1 Approach
/*vector<int> Leader(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        bool leader = true;

        for(int j = i+1; j < n; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }

        if(leader){
            ans.push_back(arr[i]);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}*/

//2 Approach
vector<int> Leader(vector<int> &arr){
    vector<int> ans;
    int n = arr.size();
    int maxi = arr[n-1];
    ans.push_back(maxi);

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> ans = Leader(arr);

    for(auto i : ans){
        cout << i << " ";
    }cout << endl;

    return 0;
}