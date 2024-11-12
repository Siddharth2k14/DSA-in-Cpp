#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//1st Approach
/*int maxSubArray(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum += nums[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}*/

//2nd Approach
/*int maxSubArray(vector<int> &nums){
    int size = nums.size();
    int maxi = INT_MIN;

    for(int i = 0; i < size; i++){
        int sum = 0;
        for(int j = i; j < size; j++){
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}*/

//3rd Approach -> Kadane's Algo
int maxSubArray(vector<int> &nums){
    int size = nums.size();
    int maxi = INT_MIN;

    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += nums[i];

        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    return maxi;
}

int main(){
    vector<int> nums = {5,4,-1,7,8};
    cout << maxSubArray(nums) << endl;

    return 0;
}