#include<iostream>
using namespace std;
void display(int arr[], int size)
{
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

void bubbleSort(int arr[], int size)
{
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[]={7,8,3,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);
    cout<<"Sorted Array is"<<endl;
    display(arr,size);
    return 0;
}