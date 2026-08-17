// Leetcode 347. Top K Frequent Elements (Optimal)
// description: Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// example: Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// required time complexity: O(nlogk) where n is the number of elements in the array
// Actual time complexity: O(nlogk) where n is the number of elements in the
// actual space complexity: O(n) where n is the number of elements in the array
// Pattern : Heap
// Difficulty : Medium

struct cmp
{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if(p1.second != p2.second)
        {
            return p1.second > p2.second; // Create Min Heap
        }
        return p1.first < p2.first; // max heap dosent matter
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Aaise elements dhundo jinka occurance at most k - 1 logo se chota ho i.e

        unordered_map<int, int> mp;
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        vector<int> res;
        // key(unique) : value
        for(auto ele : nums) // Hashmap bnao
        {
            mp[ele]++;
        }
        int i = 0;
        for(auto ele : mp) // Koi bhi k no of elements ko push kardo
        {
            pq.push(ele);
            i++;
            if(i == k) break;
        }
        auto it = mp.begin();
        advance(it, i);
        while(i < mp.size())
        {
            // (*it).second = it->second
            if(it->second > pq.top().second) // Current pq ka top abhi answer nahi ho sakta
            {
                pq.pop(); // top ko nikal do
                pq.push(*it); // Potential answer ko daal do, it points to the pair object
            }
            i++;
            it++; // Point to the next element
        }

        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};
