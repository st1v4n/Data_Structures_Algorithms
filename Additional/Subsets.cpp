/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Leetcode 78
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        int total = (1<<n);
        vector<vector<int>> result(total);
        for(int i=0;i<total;++i){
            vector<int> current;
            int mask = i;
            for(int j=0;j<n;++j){
                if(mask%2){
                    current.push_back(nums[j]);
                }
                mask >>=1;
            }
            result[i]=current;
        }
        return result;
    }
};
