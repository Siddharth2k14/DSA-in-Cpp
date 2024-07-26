#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void solve(string s, string output, int index, vector<string> &ans, string mapping[]){
    if(index >= s.length()){
        ans.push_back(output);
        return;
    }

    int number = s[index] - '0';
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++){
        output.push_back(value[i]);
        solve(s, output, index+1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCom(string s){
    vector<string> ans;
    string output;
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(s, output, index, ans, mapping);
    return ans;
}

int main(){
    string digit = "23";
    cout << "The Letter Combination is -> " << endl;
    for(auto l : letterCom(digit)){
       cout << l << " ";
    }
    cout << endl;
    return 0;
}