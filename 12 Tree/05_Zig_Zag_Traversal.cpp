// Leetcode 103. Binary Tree Zigzag Level Order Traversal
// link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool left = true;

        if(root == nullptr) return {};

        deque<TreeNode*> q;
        q.push_back(root);
        vector<vector<int>> res;
        vector<int> level;

        while(!q.empty())
        {
            int lvlsize = q.size();

            // Make current level
            while(lvlsize--)
            {
                TreeNode* tmp = q.front();
                level.push_back(tmp->val);
                q.pop_front();

                // Go to next level
                if(tmp->left != nullptr)
                {
                    q.push_back(tmp->left);
                }
                if(tmp->right != nullptr)
                {
                    q.push_back(tmp->right);
                }
            }

            if(!left)
            {
                reverse(level.begin(), level.end());
            }
            // Update answer
            res.push_back(level);

            // Clear for further pushes
            level.clear();


            left = !left;
        }

        return res;
    }
};
