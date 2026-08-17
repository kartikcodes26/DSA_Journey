// Leetcode Problem: 206. Reverse Linked List
// description: Given the head of a singly linked list, reverse the list, and return the reversed list.
// example: Input: head = [1,2,3,4,5] Output: [5,4,3,2,1]
// Difficulty: Easy
// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(1) since we are using constant space for the pointers

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
};
