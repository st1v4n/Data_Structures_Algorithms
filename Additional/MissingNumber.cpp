/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Leetcode 268
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = (n*(n+1))/2;
        for(int i=0;i<n;++i){
            expectedSum -= nums[i];
        }
        return expectedSum;
    }
};
