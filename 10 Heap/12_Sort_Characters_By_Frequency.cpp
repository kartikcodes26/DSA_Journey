// Leetcode 451. Sort Characters By Frequency
// link : https://leetcode.com/problems/sort-characters-by-frequency/
// TC : O(nlogn) SC: O(n)
// difficulty : Medium
// pattern : Heap, Hashing

class Solution {
public:
    struct comp {
        bool operator()(pair<char, int> p1, pair<char, int> p2)
        {
            return p1.second < p2.second; // max heap
        }
    };

    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ele : s)
        {
            mp[ele]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        for(auto ele : mp)
        {
            pq.push(ele);
        }

        string res;
        while(!pq.empty())
        {
            char c = pq.top().first;
            int freq = pq.top().second;
            pq.pop();
            while(freq--)
            {
                res.push_back(c);
            }
        }
        return res;
    }
};
