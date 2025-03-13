/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Leetcode 283
*/

class Solution {
public:

    void moveZeroes(vector<int>& nums) {
        int index = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=0){
                std::swap(nums[index], nums[i]);
                index++;
            }
        }
    }
};
