#include<iostream>
#include<vector>
using namespace std;

void mergeArray(vector<int> &nums1, int m, vector<int> &nums2, int n){
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while(i >= 0 && j >= 0){
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            i--;
        }
        else{
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    while(i >= 0){
        nums1[k] = nums1[i];
        i--;
        k--;
    }

    while(j >= 0){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    printf("Before\n");
    for(auto i : nums1){
        cout << i << " ";
    }cout << endl;

    vector<int> nums2 = {2,5,6};
    for(auto j : nums2){
        cout << j << " ";
    }cout << endl;
    int n = 3;
    int m = 3;

    mergeArray(nums1, m, nums2, n);

    cout << "After" << endl;
    for(auto i : nums1){
        cout << i << " ";
    }cout << endl;

    return 0;
}