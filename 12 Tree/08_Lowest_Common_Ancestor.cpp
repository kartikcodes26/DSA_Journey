// Leetocde 236. Lowest Common Ancestor of a Binary Tree
// link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(n) where n is the number of nodes in the binary tree
// Difficulty : Medium
// Pattern : Tree Traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = nullptr;
    int helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = helper(root->left, p, q);  // Left se kitne logo ka boss hai
        int right = helper(root->right, p, q); // Right se kitne logo ka boss hai
        int self = 0; // Khud ka boss hai ya nahi
        if(root == p || root == q) // Khud ka boss hai ya nahi check karo
        {
            self++;
        }
        int total = left + right + self; // Total kitne logo ka boss hai
        if(total == 2 && ans == nullptr) // Agar 2 logo ka boss hai aur pehlibaar ans aaya toh wahi ans hua
        {
            ans = root;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};
