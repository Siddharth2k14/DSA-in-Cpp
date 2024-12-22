#include<iostream>
#include<vector>
using namespace std;

//1st Approach -> Brute Force
vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, left = 0, bottom = n-1, right = m-1;

    while(top <= bottom && left <= right){
        // for printing top row
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        // for printing right column
        for(int i = top; i <= bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;

        // for printing bottom row
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // for printing left column
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ans = spiralOrder(matrix);
    
    for(auto i : ans){
        cout << i << " -> ";
    }cout << endl;

    return 0;
}