#include<iostream>
#include<vector>
using namespace std;

int singleElement(vector<int> &nums){
    int size = nums.size();
    
    int xorr = 0;
    for(int i = 0; i < size; i++){
        xorr = xorr ^ nums[i];
    }

    return xorr;
}

int main(){
    vector<int> nums = {2,2,1,1};
    int Single_Element = singleElement(nums);
    cout << "The single element present in the array is " << Single_Element << endl;

    return 0;
}