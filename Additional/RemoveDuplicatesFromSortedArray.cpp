/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Leetcode 26
*/

/*
First Solution:
Not inplace, with set
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set s(nums.begin(), nums.end());
        int iter = 0;
        for(int x:s){
            nums[iter++]=x;
        }
        return s.size();
    }
};
/*
Second Solution
Inplace, using two indexes as pointers
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int iter = 1;
        for(int i=1;i<nums.size();++i){
            if(nums[i] != nums[iter-1]){
                nums[iter++] = nums[i];
            }
        }
        return iter;
    }
};
