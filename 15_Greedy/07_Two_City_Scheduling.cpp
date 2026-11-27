// Leetcode 1029. Two City Scheduling
// Link : https://leetcode.com/problems/two-city-scheduling/
// Difficulty : Medium
// TC : O(nlogn)
// SC : O(n)
// Approach : Greedy

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> difference;
        int res = 0;
        for(auto &ele : costs)
        {
            difference.push_back({ele[0], ele[1],ele[0] - ele[1]});
        }
        sort(difference.begin(), difference.end(),
            [](vector<int> a, vector<int> b) {
                return a[2] < b[2];
        });
        for(int i = 0; i < n/2; i++)
        {
            res += difference[i][0];
        }
        for(int i = n / 2; i < difference.size(); i++)
        {
            res += difference[i][1];
        }

        return res;
    }
};
