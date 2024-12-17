#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int> nums, int target){
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int sum;
    vector<int> ans;
    while(left < right){
        sum = nums[left] + nums[right];
        if(sum == target){
            ans.push_back(left);
            ans.push_back(right);
            return ans;
        }
    }
    return {-1, -1};
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    for(auto i : ans){
        cout << i << " ";
    }cout << endl;

    return 0;
}