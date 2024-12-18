#include<iostream>
#include<vector>
using namespace std;

/*void makeRow(vector<vector<int>> &matrix, int n, int m, int i){
    for(int j = 0; j < m; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}

void makeCol(vector<vector<int>> &matrix, int n, int m, int j){
    for (int i = 0; i < n; i++){
        if (matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
        
    }
}

//1st Approach -> Brute Force Approach
vector<vector<int>> makeZeros(vector<vector<int>> &matrix, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                makeRow(matrix, n, m, i);
                makeCol(matrix, n, m, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}*/

//2nd Approach -> Better Approach
/*vector<vector<int>> makeZeros(vector<vector<int>> &matrix, int n, int m){
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}*/

//3rd Approach -> Optimal Approach
vector<vector<int>> makeZeros(vector<vector<int>> &matrix, int n, int m){
    int col0 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;

                if(j != 0){
                    matrix[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j < m; j++){
            matrix[0][j] = 0;
        }
    }

    if(col0 = 0){
        for(int i = 0; i < n; i++){
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans = makeZeros(matrix, n, m);

    for(auto it : ans){
        for(auto ele : it){
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}