#include<iostream>
#include<vector>
using namespace std;

//1st Approach -> Brute Force
/*int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }

            if(sum == k){
                count++;
            }
        }
    }

    return count;
}*/

//2nd Approach -> Better
int subarraySum(vector<int> &nums, int k){
    int count = 0;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += nums[j];

            if(sum == k){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<int> nums = {3, 1, 2, 4};
    int k = 6;
    int count = subarraySum(nums, k);

    cout << "The number of subarrays with sum " << k << " are " << count << endl;

    return 0;
}