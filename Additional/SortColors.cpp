/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
Leetcode 75
*/

class Solution {
public:

    int counts[3]{0};

    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            counts[nums[i]]++;
        }
        int iter = 0;
        for(int i=0;i<3;++i){
            for(int j=0;j<counts[i];++j){
                nums[iter++]=i;
            }
        }
    }
};
