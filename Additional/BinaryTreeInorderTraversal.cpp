/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
Leetcode 94
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

    void dfs(TreeNode* current, vector<int>& result){
        if(!current)return;
        dfs(current->left, result);
        result.push_back(current->val);
        dfs(current->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
};
