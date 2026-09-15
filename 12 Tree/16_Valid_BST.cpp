// Leetcode 98. Validate Binary Search Tree
// https://leetcode.com/problems/validate-binary-search-tree/
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(n) where n is the number of nodes in the binary tree
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
    TreeNode* prev = nullptr;
    bool ans = true;
    void helper(TreeNode* root)
    {
        if(root == nullptr)
        {
            return ;
        }
        helper(root->left);
        if(prev == nullptr)
        {
            prev = root;
        }
        else
        {
            if(prev->val >=  root->val)
            {
                ans = false;
            }
            prev = root;
        }
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
