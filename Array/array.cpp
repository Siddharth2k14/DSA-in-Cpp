#include<iostream>
#include<array>
using namespace std;

int main(){
    array<int,4> a = {1,2,3,4};
    int size = a.size();
    for(int i = 0; i < size; i++){
        cout<<a[i]<<endl;
    }

    cout<<"The element present at the front of the array is "<<a.front()<<endl;
    cout<<"The element present at the back or last of the array is "<<a.back()<<endl;
    cout<<"Array is empty "<<a.empty()<<endl;
    return 0;
}