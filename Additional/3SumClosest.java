/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Leetcode 16
*/

class Solution {

    public int abs(int number){
        return number > 0 ? number : -number;
    }

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int result = Integer.MAX_VALUE;
        int currentDifference = Integer.MAX_VALUE;
        for(int i = 0;i<nums.length - 2;++i){
            int left = i + 1;
            int right = nums.length - 1;
            while(left < right){
                int current = nums[left] + nums[right] + nums[i];
                int difference = current-target;
                if(abs(difference) < currentDifference){
                    currentDifference = abs(difference);
                    result = current;
                }
                if(difference < 0){
                    left++;
                }
                else if (difference > 0){
                    right--;
                }
                else{
                    return current;
                }
            }
        }
        return result;

    }
}
