#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool knows(vector<vector<int>> &m, int a, int b){
    if(m[a][b] == 1){
        return true;
    }
    else{
        return false;
    }
}

int celebrity(vector<vector<int>> &mat){
    stack<int> st;
    int n = mat.size();

    //Push all the elements into the stack
    for(int i = 0; i < n; i++){
        st.push(i);
    }

    //Take 2 elements from the stack till the size of the stack is 1.
    while(st.size() > 1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(mat, a, b)){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }

    int candidate = st.top();

    //Verify whether the selected candidate is a valid celebrity or not.
    bool rowCheck = false;
    int zeroCount = 0;

    for(int i = 0; i < n; i++){
        if(mat[candidate][i] == 0){
            zeroCount++;
        }
    }

    if(zeroCount == n){
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for(int i = 0; i < n; i++){
        if(mat[i][candidate] == 1){
            oneCount++;
        }
    }

    if(oneCount == n-1){
        colCheck = true;
    }

    if(rowCheck == true && colCheck == true){
        return candidate;
    }
    else{
        return -1;
    }

}

int main(){

    vector<vector<int>> mat = {{0,1,0}, {0,0,0}, {0,1,0}};
    cout << "The celebrity is " << celebrity(mat) << endl;

    return 0;
}