#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int lenOfLongestSubArrKSum(vector<int> &nums, int k){
    int size = nums.size();
    int len = 0;

    for(int i = 0; i < size; i++){
        long long sum = 0;
        for(int j = i; j < size; j++){
            sum += nums[j];

            if(sum == k){
                len = max(len, j-i+1);
            }
        }
    }
    return len;
}

int main(){
    vector<int> nums = {10, 5, 2, 7, 1, 9};
    int k = 15;

    int len = lenOfLongestSubArrKSum(nums, k);
    cout << "The longest subarray with sum k is " << len << endl;
    return 0;
}