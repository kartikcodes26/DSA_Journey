class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start1 = intervals[0][0], start2;
        int end1 = intervals[0][1], end2;
        vector<vector<int>> res;

        if(intervals.size() == 1)
        {
            return intervals;
        }
        
        for(int i = 0; i < intervals.size()-1; i++)
        {
            for(int j = 0; j < 1; j++)
            {
                start2 = intervals[i + 1][j];
                end2 = intervals[i + 1][j + 1];

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

        }
        res.push_back({start1, end1});

        return res;
    }
};
