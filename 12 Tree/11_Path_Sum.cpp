// Leetcode 112. Path Sum
// https://leetcode.com/problems/path-sum/
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(h) where h is the height of the binary tree
// Difficulty : Easy
// Pattern : Tree Traversal, DFS

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
    bool res = false;
    void helper(TreeNode* root, int target, int sum = 0)
    {
        if(root == nullptr)
        {
            return ;
        }
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum == target)
            {
                res = true;
                return;
            }
        }

        helper(root->left, target, sum);
        helper(root->right, target, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum);
        return res;
    }
};
