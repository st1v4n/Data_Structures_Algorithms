/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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

    bool check(const TreeNode* curr, int64_t min, int64_t max){
        if(!curr){
            return true;
        }
        if(curr->val <= min || curr->val >= max){
            return false;
        }
        return check(curr->left, min, curr->val) && check(curr->right, curr->val, max);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, INT64_MIN, INT64_MAX);
    }
};
