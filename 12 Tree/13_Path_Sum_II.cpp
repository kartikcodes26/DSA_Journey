// Leetocde path sum II
// problem no 113
// https://leetcode.com/problems/path-sum-ii/
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(h) where h is the height of the binary tree
// Difficulty : Medium
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
    void helper(TreeNode* root, int targetSum, vector<int> &vec,vector<vector<int>> &res,int sum = 0)
    {
        if(root == nullptr)
        {
            return ;
        }
        sum += root->val;
        vec.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            if(sum == targetSum)
            {
                res.push_back(vec);
            }
            vec.pop_back(); // Revert the last change if leaf reached
            return ;
        }
        helper(root->left, targetSum, vec, res, sum);
        helper(root->right, targetSum, vec, res, sum);
        vec.pop_back(); // Revert for non-leaf
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        vector<vector<int>> res;
        helper(root, targetSum, vec, res);
        return res;
    }
};
