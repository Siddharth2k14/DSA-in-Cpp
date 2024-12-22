#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> RotateAnti(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> temp(n, vector<int>(m, 0));
    int ind = n-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = matrix[j][ind];
        }
        ind--;
    }

    return temp;
}

int main(){
    vector < vector < int >> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = RotateAnti(arr);
    // rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
        for (int j = 0; j < rotated[0].size(); j++) {
            cout << rotated[i][j] << " ";
        } 
        cout << "\n";
    }

    return 0;
}