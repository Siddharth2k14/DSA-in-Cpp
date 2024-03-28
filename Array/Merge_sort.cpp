#include<iostream>
using namespace std;
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
}

void merge(int arr[], int mid, int si, int ei){
    int n1 = mid-si+1;
    int n2 = ei-mid;

    int arr1[n1];
    int arr2[n2];

    for(int i = 0; i < n1; i++){
        arr1[i]=arr[si+i];
    }

    for(int i = 0; i < n2; i++){
        arr2[i]=arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = si;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr[k]=arr1[i];
            k++; i++;
        }
        else{
            arr[k]=arr2[j];
            k++; j++;
        }
    }

    while(i<n1){
        arr[k]=arr1[i];
        k++; i++;
    }

    while(j<n2){
        arr[k]=arr2[j];
        k++; j++;
    }

}

void mergeSort(int arr[], int si, int ei){
    if(si<ei){
        int mid = si + (ei-si)/2;
        cout<<"The mid is "<<mid<<endl;
        mergeSort(arr, si, mid);
        mergeSort(arr, mid+1, ei);

        merge(arr, mid, si, ei);
    }
}

int main(){
    int arr[]={38,27,43,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size-1);
    display(arr, size);
    return 0;
}