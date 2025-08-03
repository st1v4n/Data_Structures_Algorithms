/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
Leetcode 238
*/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int left[] = new int[nums.length];
        int right[] = new int[nums.length];
        left[0] = nums[0];
        right[nums.length-1]=nums[nums.length-1];
        for(int i = 1;i<nums.length;++i){
            left[i] = nums[i]*left[i-1];
        }
        for(int i = nums.length - 2;i>-1;i--){
            right[i] = nums[i]*right[i+1];
        }
        int result[] = new int[nums.length];
        for(int i = 0;i<nums.length;++i){
            result[i] = 1;
            if(i-1>-1)result[i]*=left[i-1];
            if(i+1<nums.length)result[i]*=right[i+1];
        }
        return result;
    }
}
