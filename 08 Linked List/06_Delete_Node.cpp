// Leetcode 237. Delete Node in a Linked List
// Link : https://leetcode.com/problems/delete-node-in-a-linked-list/
// TC : O(1)
// SC : O(1)
// Difficulty : Easy
// Pattern : Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next == nullptr) delete node;
        swap(node->val, node->next->val);
        ListNode* temp = node->next;

        node->next = temp->next;

        delete temp;
    }
};
