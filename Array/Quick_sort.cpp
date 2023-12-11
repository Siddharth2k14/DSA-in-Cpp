#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for(int j = low; j < high; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high]; // arr[i] = pivot;
    arr[high] = temp; // pivot = temp;
    return i;
}

void Quick_sort(int arr[], int low, int high){
    if(low < high){
        int pidx = partition(arr, low, high);
        Quick_sort(arr, low, pidx-1);
        Quick_sort(arr, pidx+1, high);
    }
}

int main(){
    int arr[]={6,3,9,5,2,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    Quick_sort(arr, 0, size-1);
    display(arr, size);
    return 0;
}