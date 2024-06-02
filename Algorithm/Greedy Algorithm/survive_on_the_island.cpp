#include<iostream>
using namespace std;

int minimumDays(int s, int m, int n){
    int sundays = s/7;
    int buyingDays = s - sundays;
    int totalFood = s*m;
    int ans = 0;

    if(totalFood % n == 0){
        ans = totalFood / n;
    }
    else{
        ans = totalFood / n + 1;
    }

    if(ans <= buyingDays){
        return ans;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout << "Enter the maximum amount of food that you can buy each day" << endl;
    cin >> n;

    int m;
    cout << "Enter the amount of food required to survive one day on the island" << endl;
    cin >> m;

    int s;
    cout << "Enter the number of days required to survive" << endl;
    cin >> s;

    if(minimumDays(s, m, n) != -1){
        cout << "The minimum days survived is " << minimumDays(s, m, n) << endl;
    } 
    else{
        cout << "You cannot survive" << endl;
    }

    return 0;
}