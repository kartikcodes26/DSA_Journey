// Leetcode 973. K Closest Points to Origin
// Link : https://leetcode.com/problems/k-closest-points-to-origin/
// TC : O(nlogk) SC: O(k)
// Difficulty : Medium
// Pattern : Heap, top k

class Solution {
public:
    struct comp {
        bool operator() (pair<int, int> p1, pair<int, int> p2) {
            int d1 = (p1.first * p1.first + p1.second * p1.second);
            int d2 = (p2.first * p2.first + p2.second * p2.second);
            return d1 < d2; // min heap based on distance frm origin as we want closest point
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> pq;
        for(int i = 0; i < k; i++)
        {
            pq.push({points[i][0], points[i][1]});
        }

        for(int i = k; i < points.size(); i++)
        {
            int top_x = pq.top().first;
            int top_y = pq.top().second;
            int top_dist = (top_x * top_x + top_y * top_y);
            int curr_x = points[i][0];
            int curr_y = points[i][1];
            int curr_dist = (curr_x * curr_x + curr_y * curr_y);
            if(curr_dist < top_dist)
            {
                pq.pop();
                pq.push({curr_x, curr_y});
            }
        }

        vector<vector<int>> res;
        while(!pq.empty())
        {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }

        return res;
    }
};
