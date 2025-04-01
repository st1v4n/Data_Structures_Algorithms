/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order
Leetcode 46
*/

class Solution {
public:

    bool has(vector<int>& arr, int number){
        for(int i=0;i<arr.size();++i){
            if(arr[i]==number)return true;
        }
        return false;
    }

    void generate(vector<vector<int>>& result, vector<int>& current, vector<int>& nums){
        if(current.size()==nums.size()){
            result.push_back(current);
            return;
        }
        for(int i = 0;i<nums.size();++i){
            if(has(current, nums[i]))continue;
            current.push_back(nums[i]);
            generate(result, current, nums);
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        generate(result, curr, nums);
        return result;
    }
};
