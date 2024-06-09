#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int assignMiceHoles(int N , int M[] , int H[]) {
        sort(M, M+N);
        sort(H, H+N);
        
        int max = INT_MAX;
        for(int i = 0; i < N; i++){
            if(max < abs(H[i] - M[i])){
                max = abs(H[i] - M[i]);
            }
        }
        
        return max;
}

int main(){
    int n;
    cout << "Enter the size of the mice and holes array here:" << endl;
    cin >> n;

    int H[n];
    cout << "Enter the holes array here:" << endl;
    for(int i = 0; i < n; i++){
        cin >> H[i];
    }

    int M[n];
    cout << "Enter the mice array here:" << endl;
    for(int i = 0; i < n; i++){
        cin >> M[n];
    }

    cout << "The maximum time is -> " << assignMiceHoles(n, H, M) << endl;

    return 0;
}