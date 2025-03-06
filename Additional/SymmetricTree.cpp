/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Leetcode 101
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

    bool dfs(TreeNode* l, TreeNode* r){
        if(!l && !r)return true;
        if(l && r && l->val != r->val)return false;
        if((!l && r) ||(l && !r))return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
        
    }

    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return dfs(root->left, root->right);
    }
};
