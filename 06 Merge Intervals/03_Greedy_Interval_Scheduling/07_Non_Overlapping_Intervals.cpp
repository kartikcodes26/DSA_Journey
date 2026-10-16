// leetcode problem name : Non Overlapping Intervals
// leetcode problem no 435. Non Overlapping Intervals
// Link : https://leetcode.com/problems/non-overlapping-intervals/
// TC : O(nlogn) where n is the number of intervals
// SC : O(n) where n is the number of intervals
// difficulty : medium
// Pattern : Greedy, Sorting, Merge Intervals


class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];

        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int possibleMeetings = 0;

        // sort by end times
        sort(intervals.begin(), intervals.end(), comp);
        int lastEnd = INT_MIN;

        // First find the maximum number of non overlapping intervals
        for(int i = 0; i < intervals.size(); i++)
        {
            if(intervals[i][0] >= lastEnd)
            {
                possibleMeetings++;
                lastEnd = intervals[i][1];
            }
        }

        // the remaining inervals must be removed in order for everything to be non overlapping
        int toremove = intervals.size() - possibleMeetings;
        return toremove;
    }
};
