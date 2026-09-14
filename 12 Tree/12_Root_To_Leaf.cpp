// Leetcode no 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void helper(TreeNode* root, int digit, int &res)
    {
        if(root == nullptr)
        {
            return ;
        }
        digit = digit * 10 + (root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            res += digit;
            digit = 0;
        }
        helper(root->left, digit, res);
        helper(root->right, digit, res);
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root, 0, res);
        return res;
    }
};
