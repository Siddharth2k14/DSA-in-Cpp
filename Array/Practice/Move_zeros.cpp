#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void MoveZeros(vector<int> &nums){
    int size = nums.size();
    if(size == 0 || size == 1){
        return;
    }

    for(int i = 0; i < size; i++){
        if(nums[i] == 0){
            int element = nums[i];
            auto it = find(nums.begin(), nums.end(), element);
            if(it != nums.end()){
                nums.erase(element);
            }
            nums.push_back(element);
        }
    }

}

void display(vector<int> nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 12};
    display(nums);
    MoveZeros(nums);
    display(nums);
    return 0;
}