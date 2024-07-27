#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void solve(string str, vector<string> &ans, int index){
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.length(); j++){
        swap(str[index], str[j]);
        solve(str, ans, index+1);
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutation(string &str){
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    return ans;
}

int main(){
    string str = "abc";
    cout << "The Permutations are -> ";
    for(auto s : generatePermutation(str)){
        cout << s << " ";
    }
    cout << endl;
    return 0;
}