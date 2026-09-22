// Leetcode problem no 19. Remove Nth Node From End of List
// link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// TC : O(n)
// SC : O(1)
// Difficulty : Medium
// Pattern : Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->val = 0; // No use, just dummy
        dummy->next = head;

        ListNode* low = dummy; // Hume nth node from left ke just piche rehna hai isiliye ek extra prefix dummy node

        ListNode* high = head;

        // High ko low se n doori par rakho (Here assume low is at dummy)
        int i = 0;
        while(i < n)
        {
            high = high->next;
            i++;
        }

        // Jab high end par rahega tab low required node ke ek piche rahega
        while(high != nullptr)
        {
            low = low->next;
            high = high->next;
        }
        // Node ke piche se node ke next ke next pe point karado
        low->next = low->next->next;

        return dummy->next;
    }
};
