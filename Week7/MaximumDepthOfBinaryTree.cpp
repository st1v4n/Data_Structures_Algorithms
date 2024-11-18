//Maximum Depth of Binary Tree

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
        int res = 1;
        void getH(TreeNode* root, int curr) {
            if (!root)return;
            if (curr > res)res = curr;
            getH(root->left, curr + 1);
            getH(root->right, curr + 1);
        }
        int maxDepth(TreeNode* root) {
            if (!root)return 0;
            getH(root, 1);
            return res;
        }
};
