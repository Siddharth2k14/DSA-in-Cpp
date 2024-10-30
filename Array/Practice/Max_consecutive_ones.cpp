#include<iostream>
#include<vector>
using namespace std;

int Max_Consecutive_Ones(vector<int> &nums){
    int size = nums.size();
    int count = 0;
    int maxi = 0;

    for(int i = 0; i < size; i++){
        if(nums[i] == 1){
            count++;
            maxi = max(count, maxi);
        }
        else{
            count = 0;
        }
    }

    return maxi;
}

int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int ans = Max_Consecutive_Ones(nums);
    cout << "The maximum consecutive 1's are " << ans << endl;

    return 0;
}