#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

string First(string A){
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for(int i = 0; i < A.length(); i++){
        count[A[i]]++;
        q.push(A[i]);

        while(!q.empty()){
            int ele = q.front();
            if(count[ele] > 1){
                q.pop();
            }
            else{
                ans.push_back(ele);
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string A = "aabc";
    string ans = First(A);
    for(int i = 0; i < ans.length(); i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}