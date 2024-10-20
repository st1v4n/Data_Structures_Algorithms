/*
Given an integer array of size n, find all elements that appear more than [ n/3 ] times.
*/
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int border = nums.size() / 3;
        std::sort(nums.begin(), nums.end());
        int currCount = 1;
        vector<int> result;
        for (int i = 1;i < nums.size();i++) {
            if (nums[i] == nums[i - 1])currCount++;
            else {
                if (currCount > border) {
                    result.push_back(nums[i - 1]);
                }
                currCount = 1;
            }
        }
        if (currCount > border) {
            result.push_back(nums[nums.size() - 1]);
        }
        return result;
    }
};