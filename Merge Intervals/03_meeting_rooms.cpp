// Leetcode Problem: 252. Meeting Rooms
// description: Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
// time complexity: O(nlogn)
// space complexity: O(1)

class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());

        for(int i = 0; i < arr.size() - 1; i++)
        {
            if(arr[i][1] > arr[i+1][0])
            {
                return false;
            }
        }
        return true;
    }
};
