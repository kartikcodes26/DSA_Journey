// Leetcode problem name : Complete Binary Tree
// problem no : 958
// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(n) where n is the number of nodes in the binary tree
// Difficulty : Medium
// Pattern : Tree Traversal, BFS

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

    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr)
        {
            return false;
        }
        bool foundNull = false;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while(!dq.empty())
        {
            int lvlsize = dq.size();

            while(lvlsize--)
            {
                TreeNode* temp = dq.front();
                dq.pop_front();
                if(temp == nullptr)
                {
                    foundNull = true;
                }
                else
                {
                    if(foundNull)
                    {
                        return false;
                    }
                    dq.push_back(temp->left);
                    dq.push_back(temp->right);
                }

            }
        }
        return true;
    }
};
