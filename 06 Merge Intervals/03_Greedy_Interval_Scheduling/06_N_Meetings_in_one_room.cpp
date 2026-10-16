// gfg problem name : N Meetings in one room
// Link : https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// TC : O(nlogn) where n is the number of meetings
// SC : O(n) where n is the number of meetings
// difficulty : medium
// Pattern : Greedy, Sorting


class Solution {
  public:

    static bool comp(const vector<int>& a, const vector<int>& b)
    {
        if (a[1] == b[1])
            return a[2] < b[2];

        return a[1] < b[1];
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<vector<int>> meetings; // {Start time, end time, position}

        for(int i = 0; i < s.size();i++)
        {
            meetings.push_back({s[i], f[i], i + 1}); // 1-indexed
        }

        sort(meetings.begin(), meetings.end(), comp);
        vector<int> res;
        int lastime = -1;

        for(int i = 0; i < meetings.size(); i++)
        {
            if(meetings[i][0] > lastime)
            {
                // start new meeting
                res.push_back(meetings[i][2]);
                lastime = meetings[i][1];
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
