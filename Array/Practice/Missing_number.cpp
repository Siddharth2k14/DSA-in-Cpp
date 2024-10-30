#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums){
    int n = nums.size();
    int s1 = (n*(n+1))/2;
    int s2 = 0;

    for(int i = 0; i < n-1; i++){
        s2 += nums[i];
    }

    int misNum = s1 - s2;
    return misNum;
}

int main(){
    vector<int> a = {1, 2, 4, 5};
    int ans = missingNumber(a);
    cout << "The missing number is: " << ans << endl;
    return 0;
}