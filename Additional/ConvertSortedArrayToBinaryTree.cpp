/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
Leetcode 108
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* createNode(int start, int end, vector<int>& nums){
        if(start>end)return nullptr;
        int mid = start + (end-start)/2;
        TreeNode* curr = new TreeNode;
        curr->val = nums[mid];
        curr->left = createNode(start, mid-1, nums);
        curr->right = createNode(mid+1, end, nums);
        return curr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* result = createNode(0, nums.size()-1, nums);
        return result;
    }
};
