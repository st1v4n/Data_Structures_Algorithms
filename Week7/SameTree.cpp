/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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

    bool dfs(const TreeNode* first, const TreeNode* second){
        if(!first || !second){
            return first == second;
        }
        if(first->val != second->val)return false;
        return dfs(first->left, second->left) && dfs(first->right, second->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }
};
