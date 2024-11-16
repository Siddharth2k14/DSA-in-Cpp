#include<iostream>
#include<vector>
using namespace std;

//1 Approach
vector<int> SortParityII(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();

    vector<int> odd, even;
    for(int i = 0; i < n; i++){
        if(nums[i] % 2 == 0){
            even.push_back(nums[i]);
        }
        if(nums[i] % 2 != 0){
            odd.push_back(nums[i]);
        }
    }

    int ei = 0, oi = 0;

    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            ans.push_back(even[ei]);
            ei++;
        }
        if(i % 2 != 0){
            ans.push_back(odd[oi]);
            oi++;
        }
    }

    return ans;
}

//2 Approach
vector<int> SortParityII(vector<int> &nums){
    int n = nums.size();
    int evenIndex = 0; // Pointer for even indices
    int oddIndex = 1;  // Pointer for odd indices
    while (evenIndex < n && oddIndex < n) {
        // If evenIndex has an odd number, find a swap candidate
        if (nums[evenIndex] % 2 != 0) {
            // Ensure oddIndex points to an even number
            while (nums[oddIndex] % 2 != 0) {
                oddIndex += 2;
            }
            // Swap the values
            swap(nums[evenIndex], nums[oddIndex]);
        }
        evenIndex += 2;
    }
    return nums;
}

int main(){
    vector<int> nums = {4,2,5,7};
    vector<int> ans = SortParityII(nums);

    for(auto i : ans){
        cout << i << " ";
    }cout << endl;

    return 0;
}