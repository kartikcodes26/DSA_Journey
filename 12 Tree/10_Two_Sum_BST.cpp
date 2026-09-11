// Leetcode 653. Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// TC : O(n) where n is the number of nodes in the binary search tree
// SC : O(n) where n is the number of nodes in the binary search tree
// Difficulty : Easy
// Pattern : Tree Traversal, BST, Two pointer


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
    // In order traversal
    void helper(TreeNode* root, vector<int> &vec)
    {
        if(root == nullptr)
        {
            return ;
        }
        helper(root->left, vec);
        vec.push_back(root->val);
        helper(root->right, vec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        helper(root, nums);

        int i = 0;
        int j = nums.size() - 1;

        while(i < j)
        {
            if(nums[i] + nums[j] == k) return true;
            else if(nums[i] + nums[j] < k) i++;
            else j--;
        }

        return false;
    }
};
