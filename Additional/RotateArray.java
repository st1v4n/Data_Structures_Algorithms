/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
Leetcode 189
*/

class Solution {
    public void rotate(int[] nums, int k) {
        int[] help = new int[nums.length];
        for(int i = 0;i<nums.length;++i){
            help[(i+k)%nums.length] = nums[i];
        }
        for(int i = 0; i<nums.length;++i){
            nums[i] = help[i];
        }
    }
}
