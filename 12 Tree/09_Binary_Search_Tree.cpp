// Leetocde 700. Search in a Binary Search Tree
// link : https://leetcode.com/problems/search-in-a-binary-search-tree
// TC : O(h) where h is the height of the binary search tree
// SC : O(h) where h is the height of the binary search tree
// Difficulty : Easy
// Pattern : Tree Traversal

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val)
        {
            return root;
        }
        if(root->val > val)
        {
            return searchBST(root->left, val);
        }
        return searchBST(root->right, val);
    }
};
