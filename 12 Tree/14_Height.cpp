// gfg version of the same problem
// gfg problem name : Height of Binary Tree
// problem no : 12
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
// Note : Height of Binary Tree is defined as the number of edges in longest path from root to leaf node. If there is only one node, then height is 0. If there is no node, then height is -1.
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(h) where h is the height of the binary tree
// Difficulty : Easy
// Pattern : Tree Traversal, DFS

/* Structrue of Binary Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	int height(Node* root) {
		if (root == nullptr)
		{
			return -1; // If there is no node, then height is -1. (core difference between gfg and leetcode version)
		}

		int left = height(root->left); // Left ki height nikalo
		int right = height(root->right); // Right ki height nikalo

		int ans = 1 + max(left, right); // Root Node ki height + max(left + right)
		return ans;

	}
};


// Leetcode version of the same problem
// Leetcode no : 104
// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(h) where h is the height of the binary tree
// Difficulty : Easy
// Pattern : Tree Traversal, DFS
// Here the height of the binary tree is defined as the number of nodes in longest path from root to leaf node. If there is only one node, then height is 1. If there is no node, then height is 0.

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
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0; // If there is no node, then height is 0. (core difference between gfg and leetcode version)
        }

        int left = maxDepth(root->left); // Left ki height nikalo
        int right = maxDepth(root->right); // Right ki height nikalo

        int ans = 1 + max(left, right); // Root Node ki height + max(left + right)
        return ans;
    }
};
