// Leetcode problem number : 215
// problem name : Kth Largest Element in an Array
// problem description : Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element
// Time Complexity: O(NlogK) where N is the number of elements in the array and K is the given integer
// Space Complexity: O(K) where K is the given integer
// Difficulty Level: Medium
// Constraints:
    // 1 <= k <= nums.length <= 10^4
    // -10^4 <= nums[i] <= 10^4


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }

        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};
