/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int cache[101]{0};

    int rob(vector<int>& nums) {
        cache[0] = nums[0];
        if(nums.size() < 2){
            return nums[0];
        }
        cache[1] = std::max(nums[0], nums[1]);
        for(int i=2;i<nums.size();i++){
            cache[i] = std::max(cache[i-2] + nums[i], cache[i-1]);
        }
        return cache[nums.size()-1];
    }
};
