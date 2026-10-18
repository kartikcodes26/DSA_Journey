// LeetCode: 986. Interval List Intersections
// Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
// Return the intersection of these two interval lists.
// Time complexity: O(n + m) where n and m are the lengths of the two lists
// Space complexity: O(n + m) for the result list

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        // [2, 5], [4, 9], [5, 7]
        // [1, 4], [6, 8], [8, 10]
        int i = 0;
        int j = 0;

        int start1, start2;
        int end1, end2;
        while(i < firstList.size() && j < secondList.size())
        {
            start1 = firstList[i][0];
            start2 = secondList[j][0];

            end1 = firstList[i][1];
            end2 = secondList[j][1];

            int start = max(start1, start2);
            int end =  min(end1, end2);
            if(start <= end)
            {
                res.push_back({start, end});

            }

            if(end1 <= end2)
            {
                i++;
            }
            else
            {
                j++;
            }

        }

        return res;
    }
};
