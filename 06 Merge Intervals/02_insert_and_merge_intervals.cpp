// Leetcode Problem: 57. Insert Interval
// description: Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
// time complexity: O(nlogn) + O(n) = O(nlogn)
// space complexity: O(n)


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        bool inserted = false;

        // Inserting the interval
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= newInterval[0] && !inserted)
            {
                res.push_back(newInterval);
                inserted = true;
            }
            res.push_back(intervals[i]);
        }
        if(!inserted)
        {
            res.push_back(newInterval);
        }

        vector<vector<int>> res2;

        // Merging ranges

        if(res.empty()) return {};

        int start1 = res[0][0], start2;
        int end1 = res[0][1], end2;

        if(res.size() == 1)
        {
            return res;
        }

        for(int i = 0; i < res.size() - 1; i++)
        {

            start2 = res[i + 1][0];
            end2 = res[i + 1][1];

            if(end1 >= start2)
            {
                end1 = max(end1, end2);
            }
            else
            {
                res2.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }
        res2.push_back({start1, end1});

        return res2;hdifjfijdhd

    }
};
