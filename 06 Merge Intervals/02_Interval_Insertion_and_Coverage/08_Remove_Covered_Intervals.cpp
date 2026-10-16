// Leetcode 1288. Remove Covered Intervals
// Link : https://leetcode.com/problems/remove-covered-intervals/
// TC : O(nlogn) where n is the number of intervals
// SC : O(n) where n is the number of intervals
// difficulty : medium
// Pattern : Greedy, Sorting, Merge Intervals
class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];

        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int res = 0;
        int maxEnd = 0;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][1] > maxEnd)
            {
                res++;
                maxEnd = intervals[i][1];
            }
        }

        return res;
    }
};
