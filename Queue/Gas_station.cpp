#include<iostream>
#include<vector>
using namespace std;

int CircularTour(vector<int> &petrol, vector<int> &distance){
    int deficit = 0;
    int balance = 0;
    int start = 0;

    for(int i = 0; i < petrol.size(); i++){
        balance += petrol[i] - distance[i];
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0){
        return start;
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    vector<int> petrol(n), distance(n);
    
    cout << "Enter the petrol available at each pump: ";
    for(int i = 0; i < n; i++){
        cin >> petrol[i];
    }

    cout << "Enter the distance from each pump to the next: ";
    for(int i = 0; i < n; i++){
        cin >> distance[i];
    }

    int start = CircularTour(petrol, distance);

    if(start == -1){
        cout << "No solution exists.\n";
    }
    else{
        cout << "Start the tour from petrol pump " << start << ".\n";
    }

    return 0;
}