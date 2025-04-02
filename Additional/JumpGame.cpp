/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
Leetcode 55
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i=0;i<nums.size();++i){
            if(maxReach < i)return false;
            maxReach=std::max(maxReach, nums[i]+i);
        }
        return true;
    }
};
