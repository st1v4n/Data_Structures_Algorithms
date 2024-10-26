/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        result[0] = result[1] = -1;
        int left = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (left >= nums.size() || nums[left] != target) {
            return result;
        }
        int right = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        result[0] = left;
        result[1] = right;
        return result;
    }
};