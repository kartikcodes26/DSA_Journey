// Leetcode problem Name : 23. Merge k Sorted Lists
// Link : https://leetcode.com/problems/merge-k-sorted-lists/
// TC : O(NlogK)
// Difficulty : Hard
// Pattern : Heap, Linked Lists
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
    struct comp {
        bool operator()(pair<int, ListNode*> p1, pair<int, ListNode*> p2) {
            return p1.first > p2.first; // min heap
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, comp> pq;
        for(auto ele : lists)
        {
            if(ele != nullptr)
            {
                pq.push({ele->val, ele});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        bool headObtained = false;
        while(!pq.empty())
        {
            // take out the min element
            ListNode* topNode = pq.top().second;
            pq.pop();

            // Add it into the list
            temp->next = topNode;

            // Move temp ahead
            temp = temp->next;

            // Add the next nodes
            if(topNode->next != nullptr)
            {
                pq.push({topNode->next->val, topNode->next});
            }
        }

        return dummy->next;
    }
};
