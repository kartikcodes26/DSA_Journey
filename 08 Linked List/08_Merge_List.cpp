// Leetcode 21. Merge Two Sorted Lists
// link : https://leetcode.com/problems/merge-two-sorted-lists/
// TC : O(n + m) where n and m are the number of nodes in the two linked lists
// SC : O(1) since we are using constant space for the pointers
// Difficulty : Easy
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *h1 = list1;
        ListNode *h2 = list2;
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;

        while(h1 != nullptr && h2 != nullptr)
        {
            if(h1->val < h2->val)
            {
                dummy->next = h1;
                h1 = h1->next;
            }
            else
            {
                dummy->next = h2;
                h2 = h2->next;
            }
            dummy = dummy->next;
        }
        while(h1 != nullptr)
        {
            dummy->next = h1;
            h1 = h1->next;
            dummy = dummy->next;
        }
        while(h2 != nullptr)
        {
            dummy->next = h2;
            h2 = h2->next;
            dummy = dummy->next;
        }
        dummy->next = nullptr; // Unnessary bcz remaining list already ends in nullptr

        return res->next;
    }
};
