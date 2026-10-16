// Leetcode problem no : 1851. Minimum Interval to Include Each Query
// link: https://leetcode.com/problems/minimum-interval-to-include-each-query/
// Time Complexity: O(nlogn + mlogm + nlogm)
// Space Complexity: O(n + m)
// Difficulty: Hard
// Pattern: Intervals, min-heap, sorting

class Solution {
public:

    // Custom comparator to sort pairs by interval size in ascending order (min-heap)
    struct CompareInterval {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            int sizeA = a.second - a.first + 1;
            int sizeB = b.second - b.first + 1;

            // If sizes are equal, you can optionally tie-break by the start element
            if (sizeA == sizeB) {
                return a.first > b.first;
            }

            // Return true if 'a' has a larger size than 'b' to make it a min-heap
            return sizeA > sizeB;
        }
    };

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int,int>> indices(queries.size());
        vector<int> res(queries.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareInterval> minHeap;

        for(int i = 0; i < indices.size(); i++)
        {
            indices[i] = {queries[i], i};
        }

        sort(indices.begin(), indices.end());

        int intervalindex = 0;
        for(auto [query, index] : indices)
        {
            while(intervalindex < intervals.size() && intervals[intervalindex][0] <= query)
            {
                int left = intervals[intervalindex][0];
                int right = intervals[intervalindex][1];

                if(right >= query)
                {
                    minHeap.push({left, right});
                }
                intervalindex++;
            }

            while(!minHeap.empty() && minHeap.top().second < query)
            {
                minHeap.pop();
            }

            if(minHeap.empty())
            {
                res[index] = -1;
            }
            else
            {
                int left = minHeap.top().first;
                int right = minHeap.top().second;
                res[index] = right - left + 1;
            }
        }
        return res;
    }
};
