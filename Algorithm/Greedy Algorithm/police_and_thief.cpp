#include<iostream>
using namespace std;

int CatchThieves(char arr[], int n, int k){
    int pol = -1;
    int thi = -1;
    int ans = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 'P'){
            pol = i;
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(arr[i] == 'T'){
            thi = i;
            break;
        }
    }

    if(thi == -1 && pol == -1){
        return -1;
    }

    while(thi <  n && pol < n){
        if(abs(pol - thi) <= k){

            pol = pol + 1;
            while(pol < n && arr[pol] != 'P'){
                pol = pol + 1;
            }

            thi = thi + 1;
            while(thi < n && arr[thi] != 'T'){
                thi = thi + 1;
            }

            ans = ans + 1;
        }

        else if(thi < pol){
            thi = thi + 1;
            while(thi < n && arr[thi] != 'T'){
                thi = thi + 1;
            }
        }

        else{
            pol = pol + 1;
            while(pol < n && arr[pol] != 'P'){
                pol = pol + 1;
            }
        }
    }

    return ans;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array here: " << endl;
    cin >> n;

    int k;
    cout << "Enter the value of k here: " << endl;
    cin >> k;

    char arr[n];
    cout << "Enter the array of policemen and thieves here: " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Number of theieves that can be catched are: " << CatchThieves(arr, n, k) << endl;

    return 0;
}