/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
Leetcode 73
*/

class Solution {
public:

    void setting(vector<vector<bool>>& table, vector<vector<int>>& matrix, int rows, int cols, int posX, int posY){
        for(int i=0;i<cols;++i){
            if(matrix[posX][i] == 0 && !table[posX][i])continue;
            table[posX][i] = true;
            matrix[posX][i] = 0;
        }
        for(int i=0;i<rows;++i){
            if(matrix[i][posY]==0 && !table[i][posY])continue;
            table[i][posY] = true;
            matrix[i][posY] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> table(rows, vector<bool>(cols, 0));
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(matrix[i][j] == 0 && table[i][j] == false){
                    setting(table, matrix, rows, cols, i, j);
                }
            }
        }
    }
};
