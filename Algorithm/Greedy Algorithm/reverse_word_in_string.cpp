#include<iostream>
#include<algorithm>
using namespace std;

string reverse_words(string s){
    string ans = "";
    string temp = "";
    for(int i = s.length()-1; i >= 0; i--){
        if(s[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans = ans + temp;
            ans.push_back('.');
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }
    }

    reverse(temp.begin(), temp.end());
    ans = ans + temp;
    return ans;
}

int main(){
    string s;
    cout << "Enter the string here" << endl;
    cin >> s;

    cout << "The reversed string is" << reverse_words(s) << endl;
    return 0;
}