class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();

        if(intervals.empty())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        if(intervals.size() == 1)
        {
            if(newInterval[0] < inverals[0][0])
            {
                intervals.insert(intervals.begin(), newInterval);
            }
            else if (newInterval[0] > intervals[0][0])
            {
                intervals.push_back(newInterval);
            }
            return intervals;
        }


        for(int i = 0; i < intervals.size() - 1; i++)
        {
            if(newInterval[0] <= intervals[0][0])
            {
                intervals.insert(intervals.begin(), newInterval);
                break;
            }
            else if (newInterval[0] >= intervals[n - 1][0])
            {
                intervals.push_back(newInterval);
                break;
            }

            if(newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i + 1][0])
            {
                intervals.insert(intervals.begin() + i + 1, newInterval);
                break;
            }
        }
    }
};
