// Leetcode problem Name : 373. Find K Pairs with Smallest Sums
// Link : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// TC : O(KlogK) SC : O(K)
// Difficulty : Medium
// Pattern : Heap, two pointer

class Solution {
public:
    struct comp {
        bool operator()(pair<int, pair<int, int>> p1,
                        pair<int, pair<int, int>> p2) {
            return p1.first > p2.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2, int k) {
        vector<vector<int>> res;

        if (nums1.empty() || nums2.empty() || k <= 0)
            return res;

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            comp
        > pq;

        set<pair<int, int>> vis;

        pq.push({nums1[0] + nums2[0], {0, 0}});
        vis.insert({0, 0});

        while (k > 0 && !pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int i = p.second.first;
            int j = p.second.second;

            res.push_back({nums1[i], nums2[j]});
            k--;

            // Next pair in nums1 direction
            if (i + 1 < nums1.size() &&
                vis.find({i + 1, j}) == vis.end()) {

                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                vis.insert({i + 1, j});
            }

            // Next pair in nums2 direction
            if (j + 1 < nums2.size() &&
                vis.find({i, j + 1}) == vis.end()) {

                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                vis.insert({i, j + 1});
            }
        }

        return res;
    }
};
