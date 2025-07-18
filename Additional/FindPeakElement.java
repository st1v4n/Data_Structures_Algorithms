/*
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.
Leetcode 162
*/

class Solution {
    public int findPeakElement(int[] nums) {
        int middle;
        int start = 0;
        int end = nums.length - 1;
        while(start <= end){
            middle = start + (end - start)/2;
            int left = middle - 1 < 0 ? Integer.MIN_VALUE : nums[middle-1];
            int right = middle + 1 >= nums.length ? Integer.MIN_VALUE : nums[middle+1]; 
            if(left > nums[middle]){
                end = middle;
            }
            else if(right > nums[middle]){
                start = middle + 1;
            }
            else{
                return middle;
            }
        }
        return 0;
    }
}
