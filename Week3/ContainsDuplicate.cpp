/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto start = nums.begin();
        auto end = nums.end();
        std::sort(start, end);
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};