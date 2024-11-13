#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeSumValues(vector<vector<int>> &nums1, vector<vector<int>> &nums2){
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<vector<int>> result;
    int i = 0;
    int j = 0;

    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i][0] == nums2[j][0]){
            result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++;
            j++;
        }
        else if(nums1[i][0] < nums2[j][0]){
            result.push_back(nums1[i]);
            i++;
        }
        else{
            result.push_back(nums2[j]);
            j++;
        }
    }

    while(i < nums1.size()){
        result.push_back(nums1[i]);
        i++;
    }

    while(j < nums2.size()){
        result.push_back(nums2[j]);
    }

    return result;
}

int main(){
    vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}};
    vector<vector<int>> nums2 = {{1,4},{3,2},{4,1}};
    vector<vector<int>> ans = mergeSumValues(nums1, nums2);

    for(auto i : ans){
        for(auto j : i){
            cout << (i, j) << ",";
        }
        cout << endl;
    }

    return 0;
}