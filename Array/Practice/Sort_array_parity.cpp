#include<iostream>
#include<vector>
using namespace std;

//1 Approach
/*vector<int> SortParity(vector<int> &nums){
    vector<int> ans;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        if(nums[i] % 2 == 0){
            ans.push_back(nums[i]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] % 2 != 0){
            ans.push_back(nums[i]);
        }
    }

    return ans;
}*/

//2 Approach
vector<int> SortParity(vector<int> &nums){
    int n = nums.size();
    int left = 0;
    int right = n-1;

    while(left < right){
        if(nums[left] % 2 == 0){
            left++;
        }
        else if(nums[right] % 2 != 0){
            right--;
        }
        else{
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    return nums;
}

int main(){
    vector<int> nums = {3, 1, 2, 4};
    vector<int> ans = SortParity(nums);

    for(auto i : ans){
        cout << i << " ";
    }cout << endl;

    return 0;
}