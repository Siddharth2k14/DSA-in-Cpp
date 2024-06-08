#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int minNumberOfSwaps(string s){
    vector<int> pos;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '['){
            pos.push_back(i);
        }
    }

    int count = 0;
    int p = 0;
    int sum = 0;

    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '['){
            ++count;
            ++p;
        }
        else if(s[i] == ']'){
            --count;
        }

        if(count < 0){
            sum = sum + (pos[p] - i);
            swap(s[i], s[pos[p]]);
            ++p;

            count = 1;
        }
    }

    return sum;
}

int main(){
    string bracket;
    cout << "Enter the equal sequence of bracket here" << endl;
    cin >> bracket;

    cout << "The minimum number of swaps required to balance the sequence is -> " << minNumberOfSwaps(bracket) << endl;

    return 0;
}