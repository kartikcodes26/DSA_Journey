// Leetcode 347. Top K Frequent Elements
// description: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// example: Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// required time complexity: O(nlogn) where n is the number of elements in the array
// Actual time complexity: O(nlogn) where n is the number of elements in the array
// actual space complexity: O(n) where n is the number of elements in the array
// Pattern : Heap
// Difficulty : Medium

struct cmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if(p1.second != p2.second)
        {
            return p1.second < p2.second; // Max heap
        }
        return p1.first < p2.first; // Max heap (Dosent matter)
    }
};

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        vector<int> res;
        for(auto ele : nums)
        {
            mp[ele]++;
        }
        for(auto ele : mp)
        {
            pq.push(ele);
        }
        for(int i = 0; i < k; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;


    }
};
