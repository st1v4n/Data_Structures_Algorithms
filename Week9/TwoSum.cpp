/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> umap;
        std::vector<int> res(2);
        for(int i=0;i<nums.size();i++){
            umap[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            if(umap[target - nums[i]] && i!=umap[target-nums[i]]){
                res[0] = i;
                res[1] = umap[target - nums[i]];
                return res;
            }
        }
        return res;
    }
};
