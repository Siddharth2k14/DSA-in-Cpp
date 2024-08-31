#include<iostream>
using namespace std;

class Nstacks{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

    public:
    Nstacks(int N, int S){
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //Initialization of top array
        for(int i = 0; i < n; i++){
            top[i] = -1;
        }

        //Initialization of the next array
        for(int i = 0; i < s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
        freespot = 0;
    }

    bool push(int x, int m){
        if(freespot == -1){
            return false;
        }

        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main(){

    // Number of stacks and size of array
    int N = 3, S = 10;
    
    // Create an N-stack array of size S
    Nstacks ns(N, S);

    // Pushing elements into different stacks
    ns.push(10, 1); // Push 10 into stack 1
    ns.push(20, 1); // Push 20 into stack 1
    ns.push(30, 2); // Push 30 into stack 2
    ns.push(40, 3); // Push 40 into stack 3

    // Popping elements from stacks
    cout << "Popped from stack 1: " << ns.pop(1) << endl;
    cout << "Popped from stack 2: " << ns.pop(2) << endl;
    cout << "Popped from stack 3: " << ns.pop(3) << endl;

    // Trying to pop from an empty stack
    cout << "Popped from stack 3: " << ns.pop(3) << endl; // Should return -1

    return 0;
}