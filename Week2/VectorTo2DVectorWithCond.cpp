/*
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int app[201]{ 0 };
        int max_number = nums[0];
        for (int i = 0;i < nums.size();i++) {
            app[nums[i]]++;
            if (nums[i] > max_number) {
                max_number = nums[i];
            }
        }
        int max_occ = 0;
        for (int i = 0;i < 201;i++) {
            if (max_occ < app[i]) {
                max_occ = app[i];
            }
        }
        vector<vector<int>> result(max_occ);
        for (int i = 0;i < max_occ;i++) {
            for (int j = 0;j <= max_number;j++) {
                if (app[j] != 0) {
                    result[i].push_back(j);
                    app[j]--;
                }
            }
        }
        return result;
    }
};