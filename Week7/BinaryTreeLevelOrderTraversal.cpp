//Binary tree Level order Traversal


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
        vector<vector<int>> levelOrder(TreeNode* root) {
            if (!root)return {};
            queue<TreeNode*> q;
            q.push(root);
            vector<vector<int>> res;
            while (q.size()) {
                vector<int> curr(q.size());
                for (int i = 0; i < curr.size();i++) {
                    TreeNode* first = q.front();
                    q.pop();
                    curr[i] = first->val;

                    if (first->left) {
                        q.push(first->left);
                    }
                    if (first->right) {
                        q.push(first->right);
                    }
                }
                res.push_back(curr);
            }
            return res;
        }
};