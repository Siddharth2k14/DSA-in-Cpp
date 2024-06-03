#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int minimumChocolate(int n, int m, vector<int> chocolates){
    sort(chocolates.begin(), chocolates.end());
    int i = 0;
    int j = m-1;
    int mini = INT_MAX;

    while(j < chocolates.size()){
        int diff = chocolates[j] - chocolates[i];
        mini = min(mini, diff);
        i++;
        j++;
    }

    return mini;
}

int main(){
    int n, m;
    cout << "Enter the number of students: ";
    cin >> n;
    cout << "Enter the number of types of chocolate bars: ";
    cin >> m;

    vector<int> choco(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the quantity of chocolate bar " << i+1 << ": ";
        cin >> choco[i];
    }

    int minDiff = minimumChocolate(n, m, choco);
    cout << "The minimum difference between the number of chocolate bars that two students can have is: " << minDiff << endl;

    return 0;
}