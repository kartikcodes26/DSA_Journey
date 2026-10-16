// Leetcode no 452. Minimum Number of Arrows to Burst Balloons
// Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-ballo
// TC : O(nlogn) where n is the number of intervals
// SC : O(n) where n is the number of intervals
// difficulty : medium
// Pattern : Greedy, Sorting, Merge Intervals

class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0 || points.size() == 1) return points.size();
        sort(points.begin(), points.end(), comp);
        int lastend = points[0][1];

        int arrows = 1;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] > lastend)
            {
                arrows++;
                lastend = points[i][1];
            }
        }

        return arrows;

    }
};
