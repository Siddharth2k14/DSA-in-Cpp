#include<iostream>
using namespace std;
void display(int arr[], int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

void Insertion_Sort(int arr[], int size){
    for(int i=1;i<size;i++){
        int current_val=arr[i];
        int j=i-1;
        while(arr[j]>current_val && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current_val;
    }
}
int main()
{
    int arr[]={7,8,3,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);

    Insertion_Sort(arr,size);
    display(arr,size);
    return 0;
}