#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//Using vectors
int maxEqualSum(vector<int> &s1, vector<int> &s2, vector<int> &s3){
    int n1 = s1.size();
    int n2 = s2.size();
    int n3 = s3.size();

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    
    //Storing the sum of the elements of s1
    for(int i = 0; i < n1; i++){
        sum1 = sum1 + s1[i];
    }

    //Storing the sum of the elements of s2
    for(int i = 0; i < n2; i++){
        sum2 = sum2 + s2[i];
    }

    //Storing the sun of the elements of s3
    for(int i = 0; i < n3; i++){
        sum3 = sum3 + s3[i];
    }

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;

    while(true){
        //If anyone of the stack is empty or not
        if(top1 == n1 || top2 == n2 || top3 == n3){
            return 0;
        }

        //If sum of all the stacks are equal
        if(sum1 == sum2 && sum2 == sum3){
            return sum1;
        }

        //If sum1 is greater than other two
        if(sum1 >= sum2 && sum1 >= sum3){
            sum1 = sum1 - s1[top1];
            top1++;
        }

        //If sum2 is greater than other two
        else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 = sum2 - s2[top2];
            top2++;
        }

        //If sum3 is greater than other two
        else if(sum3 >= sum1 && sum3 >= sum2){
            sum3 = sum3 - s3[top3];
            top3++;
        }
    }
}

//Using stacks
int maxEqualSum(stack<int> &s1, stack<int> &s2, stack<int> &s3){
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    stack<int> temp1 = s1;
    stack<int> temp2 = s2;
    stack<int> temp3 = s3;

    while(!temp1.empty()){
        sum1 = sum1 + temp1.top();
        temp1.pop();
    }

    while(!temp2.empty()){
        sum2 = sum2 + temp2.top();
        temp2.pop();
    }

    while(!temp3.empty()){
        sum3 = sum3 + temp3.top();
        temp3.pop();
    }

    while(true){
        //If anyone of the stack is empty or not
        if(s1.empty() || s2.empty() || s3.empty()){
            return 0;
        }

        if(sum1 == sum2 && sum2 == sum3){
            return sum1;
        }

        //If sum1 is greater than other two
        if(sum1 >= sum2 && sum1 >= sum3){
            sum1 -= s1.top();
            s1.pop();
        }

        //If sum2 is greater than other two
        else if(sum2 >= sum1 && sum2 >= sum3){
            sum2 -= s2.top();
            s2.pop();
        }

        //If sum3 is greater than other two
        else if(sum3 >= sum1 && sum3 >= sum2){
            sum3 -= s3.top();
            s3.pop();
        }
    }
}


int main(){
    int choice;
    cout << "Enter the choice 1 for vectors and 2 for stacks and 3 for exit" << endl;
    cin >> choice;

    int n1, n2, n3;
    vector<int> v1(n1), v2(n2), v3(n3);
    stack<int> s1, s2, s3;
    switch(choice){
        case 1:
            cout << "Enter the number of elements in vector 1: ";
            cin >> n1;
            cout << "Enter the number of elements in vector 2: ";
            cin >> n2;
            cout << "Enter the number of elements in vector 3: ";
            cin >> n3;


            cout << "Enter elements for vector 1: ";
            for (int i = 0; i < n1; i++) {
                cin >> v1[i];
            }

            cout << "Enter elements for vector 2: ";
            for (int i = 0; i < n2; i++) {
                cin >> v2[i];
            }

            cout << "Enter elements for vector 3: ";
            for (int i = 0; i < n3; i++) {
                cin >> v3[i];
            }
            
            cout << "Max equal sum using vectors: " << maxEqualSum(v1, v2, v3) << endl;
        
        case 2:
            cout << "Enter the number of elements in stack 1: ";
            cin >> n1;
            cout << "Enter the number of elements in stack 2: ";
            cin >> n2;
            cout << "Enter the number of elements in stack 3: ";
            cin >> n3;

            cout << "Enter elements for stack 1: ";
            for (int i = 0; i < n1; i++) {
                int element;
                cin >> element;
                s1.push(element);
            }

            cout << "Enter elements for stack 2: ";
            for (int i = 0; i < n2; i++) {
                int element;
                cin >> element;
                s2.push(element);
            }

            cout << "Enter elements for stack 3: ";
            for (int i = 0; i < n3; i++) {
                int element;
                cin >> element;
                s3.push(element);
            }

            cout << "Max equal sum using stacks: " << maxEqualSum(s1, s2, s3) << endl;
        
        default:
            return 0;
    }

    return 0;
}