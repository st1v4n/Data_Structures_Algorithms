/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Leetcode 53
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int result = INT32_MIN;
        for(int i=0;i<nums.size();++i){
            sum = std::max(nums[i], sum + nums[i]);
            result = std::max(result, sum);
        }
        return result;
    }
};
