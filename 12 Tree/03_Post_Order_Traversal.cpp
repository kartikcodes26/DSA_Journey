// gfg problem name : Postorder Traversal of Binary Tree
// link : https://practice.geeksforgeeks.org/problems/postorder-traversal/1
// TC : O(n) where n is the number of nodes in the binary tree
// SC : O(n) where n is the number of nodes in the binary tree
// Difficulty : Easy
// Pattern : Tree Traveral

/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void traversal(vector<int> &res, Node* root)
    {
        if(root == nullptr)
        {
            return ;
        }

        traversal(res, root->left);
        traversal(res, root->right);
        res.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        // code here
        vector<int> res;
        traversal(res, root);

        return res;
    }
};
