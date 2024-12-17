#include<iostream>
#include<vector>
#include<map>
using namespace std;

//1st approach
/*int MajorityElement(vector<int> &nums){
    int n = nums.size();

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(nums[j] == nums[i]){
                count = count + 1;
            }
        }

        if(count > n/2){
            return nums[i];
        }
    }
    return -1;
}*/

//2nd Approach
/*int MajorityElement(vector<int> &nums){
    int n = nums.size();
    map<int, int> count;

    for(int i = 0; i < n; i++){
        count[nums[i]]++;
    }

    for(auto i : count){
        if(i.second > n/2){
            return i.first;
        }
    }

    return -1;
    
}*/

//3rd Approach
int MajorityElement(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    int element;

    for(int i = 0; i < n; i++){
        if(count == 0){
            count = 1;
            element = nums[i];
        }
        else if(element == nums[i]){
            count = count + 1;
        }
        else{
            count = count - 1;
        }
    }

    //Checking for majority element in the array
    int count1 = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] == element){
            count1++;
        }
    }

    if(count1 > n/2){
        return element;
    }
    return -1;
}

int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << MajorityElement(nums) << endl;

    return 0;
}