#include<iostream>
using namespace std;

void display(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

void Selection_sort(int arr[],int size){
    for(int i = 0; i < size-1; i++){
        int smallest = i;
        for(int j = i+1; j < size; j++){
            if(arr[smallest]>arr[j]){
                smallest = j;
            }
        }
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}
int main()
{
    int arr[]={7,8,3,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    Selection_sort(arr,size);
    display(arr,size);
    return 0;
}