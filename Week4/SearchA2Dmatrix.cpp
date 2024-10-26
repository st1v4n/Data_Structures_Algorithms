/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int sizeRow = matrix[0].size();
        int start = 0;
        int end = sizeRow * matrix.size();
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid / sizeRow][mid % sizeRow] == target) {
                return true;
            }
            if (matrix[mid / sizeRow][mid % sizeRow] > target) {
                end = mid - 1;
                continue;
            }
            start = mid + 1;
            if (start / sizeRow >= matrix.size() || start % sizeRow >= sizeRow)return false;
        }
        return false;
    }
};