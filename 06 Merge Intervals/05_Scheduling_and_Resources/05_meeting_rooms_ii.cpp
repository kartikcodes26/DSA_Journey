// Leetcode 253. Meeting Rooms II
// description: Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
// time complexity: O(nlogn)
// space complexity: O(n)
// difficulty : Medium

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {

        vector<int> start;
        vector<int> end;
        for(auto ele : intervals)
        {
            start.push_back(ele.start);
        }
        for(auto ele2 : intervals)
        {
            end.push_back(ele2.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(),end.end());

        int i = 0;
        int j = 0;

        int res = 0;
        int count = 0;
        while(i < start.size() && j < end.size())
        {
            if(start[i] < end[j])
            {
                // A meeting has started
                count++;
                i++;
            }
            else
            {
                // A meeting has ended
                count--;
                j++;
            }

            res = max(res, count);
        }


        return res;
    }
};
