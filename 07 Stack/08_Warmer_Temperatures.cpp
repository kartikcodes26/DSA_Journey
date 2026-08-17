// Leetcode problem no: 739. Daily Temperatures
// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size());

        for(int i = temperatures.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                res[i] = 0;
            }
            else
            {
                res[i] = abs(st.top() - i);
            }
            st.push(i);

        }

        return res;

    }
};
