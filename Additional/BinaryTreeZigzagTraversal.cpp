/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
Leetcode 103
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>> result;
        bool LeftToRight = true;
        deque<TreeNode*> q;
        q.push_front(root);
        int iter=0;
        while(q.size()){
            int levelSize = q.size();
            result.push_back({});
            for(int i=0;i<levelSize;++i){
                if(LeftToRight){
                    if (q.back()->left)
                    {
                        q.push_front(q.back()->left);
                    }
                    if (q.back()->right)
                    {
                        q.push_front(q.back()->right);
                    }
                    result[iter].push_back(q.back()->val);
                    q.pop_back();
                }
                else{
                    if (q.front()->right)
                    {
                        q.push_back(q.front()->right);
                    }
                    if (q.front()->left)
                    {
                        q.push_back(q.front()->left);
                    }
                    result[iter].push_back(q.front()->val);
                    q.pop_front();
                }
            }
            LeftToRight = !LeftToRight;
            iter++;
        }
        return result;
    }
};
