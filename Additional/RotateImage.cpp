/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
Leetcode 48
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       // transpose -> reverse
       int n = matrix.size();
       int end = n/2;
       for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            std::swap(matrix[i][j], matrix[j][i]);
        }
       }
       for(int i=0;i<n;++i){
        for(int j=0;j<end;++j){
            std::swap(matrix[i][j], matrix[i][n-j-1]);
        }
       }
    }
};
