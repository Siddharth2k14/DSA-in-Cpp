#include<iostream>
using namespace std;

class TwoStacks{
    private:
        int *arr;
        int top1;
        int top2;
        int size;

    public:
        TwoStacks(int s){
            this->size = s;
            top1 = -1;
            top2 = size;
            arr = new int[s];
        }
        void push1(int x){
            if(top2-top1 > 1){
                top1++;
                arr[top1] = x;
            }
        }

        void push2(int x){
            if(top2 - top1 > 1){
                top2--;
                arr[top2] = x;
            }
        }

        int pop1(){
            if(top1 >= 0){
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else{
                return -1;
            }
        }

        int pop2(){
            if(top2 < size){
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else{
                return -1;
            }
        }

};

int main(){

    TwoStacks ts(5);

    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push2(40);
    ts.push1(50);

    cout << "Popped element from Stack1: " << ts.pop1() << endl;
    cout << "Popped element from Stack2: " << ts.pop2() << endl;

    ts.push2(60);

    cout << "Popped element from Stack1: " << ts.pop1() << endl;
    cout << "Popped element from Stack2: " << ts.pop2() << endl;

    return 0;
}