/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.
Leetcode 111
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    public int currValue = Integer.MAX_VALUE;

    public void dfs(TreeNode curr, int integer){
        if(curr.left == null && curr.right == null){
            currValue = Integer.min(currValue, integer);
            return;
        }
        if(curr.left != null)dfs(curr.left, integer+1);
        if(curr.right != null)dfs(curr.right, integer+1);
    }

    public int minDepth(TreeNode root) {
        int result = 1;
        if(root == null)return 0;
        dfs(root, result);
        return currValue;
    }
}
