//Binary tree preorder traversal

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
        void f(TreeNode* root, vector<int>& r) {
            if (!root)return;
            r.push_back(root->val);
            f(root->left, r);
            f(root->right, r);
        }

        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> result;
            f(root, result);
            return result;
        }
};
