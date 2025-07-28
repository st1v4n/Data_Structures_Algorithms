/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
Leetcode 643
*/

class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int currentSum = 0;
        double result = Integer.MIN_VALUE;
        for(int i =0;i<=nums.length-k;++i){
            if(i>0){
                currentSum-=nums[i-1];
                currentSum+=nums[i-1+k];
            }
            else{
                for(int j = 0;j<k;++j){
                    currentSum+=nums[j];
                }
            }
            result = Double.max(result, (currentSum*1.0)/k);
        }
        return result;
    }
}
