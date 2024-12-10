#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<unordered_set>
using namespace std;


//Brute force
/*bool LinearSearch(vector<int> &nums, int x)
{
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == x)
        {
            return true;
        }
    }
    return false;
}

int LongestConsecutiveSequence(vector<int> &nums)
{
    int size = nums.size();
    int longest = 1;

    for(int i = 0; i < size; i++)
    {
        int x = nums[i];
        int count = 1;

        while(LinearSearch(nums, x) == true)
        {
            x += 1;
            count += 1;
        }

        longest = max(longest, count);
    }
    
    return longest;
}*/

//Better
/*int LongestConsecutiveSequence(vector<int> &nums){
    int size = nums.size();
    if(size == 0){
        return 0;
    }

    sort(nums.begin(), nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 0;

    for(int i = 0; i <  size; i++){
        if(nums[i] - 1 == lastSmaller){
            cnt += 1;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller){
            cnt = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, cnt);
    }

    return longest;
}*/

//Optimal
int LongestConsecutiveSequence(vector<int> &nums){
    int size = nums.size();
    if(size == 0){
        return 0;
    }

    unordered_set<int> s;
    for(int i = 0; i < size; i++){
        s.insert(nums[i]);
    }

    int longest = 1;
    for(auto it : s){
        if(s.find(it-1) == s.end()){
            int cnt = 1;
            int x = it;
            while(s.find(x+1) != s.end()){
                x += 1;
                cnt += 1;
            }

            longest = max(longest, cnt);
        }
    }

    return longest;

}

int main()
{
    vector<int> nums = {100, 200, 1, 3, 2, 4};
    int ans = LongestConsecutiveSequence(nums);
    cout << ans << endl;

    return 0;
}