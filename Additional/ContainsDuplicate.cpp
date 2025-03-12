/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
Leetcode 217
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int i=0;i<nums.size();++i){
            if(uset.count(nums[i]))return true;
            uset.insert(nums[i]);
        }
        return false;
    }
};
