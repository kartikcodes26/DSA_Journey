// Leetcode Problem: 56. Merge Intervals
// description: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
// time complexity: O(nlogn)
// space complexity: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {


        // [1,3] [2,9] [9, 12] [15, 17] [21, 36]
        sort(intervals.begin(), intervals.end());

        int start1 = intervals[0][0], start2;
        int end1 = intervals[0][1], end2;

        vector<vector<int>> res;
        if(intervals.empty()) return {};

        if(intervals.size() == 1)
        {
            return intervals;
        }

        for(int i = 0; i < intervals.size() - 1; i++)
        {

            start2 = intervals[i + 1][0];
            end2 = intervals[i + 1][1];

            if(end1 >= start2)
            {
                end1 = max(end1, end2);
            }
            else
            {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res.push_back({start1, end1});

        return res;
    }
};
