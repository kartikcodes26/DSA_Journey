// gfg problem name : 0-1 Knapsack Problem
// problem link : https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// TC : O(N*W) where N is the number of items and W is the maximum weight of knapsack SC : O(N*W) for dp array
// Difficulty : Medium
// Pattern : Dynamic Programming
// Approach : Memoisation

class Solution {
  public:
    int helper(int i, vector<int> &val, vector<int> &wt, int W, vector<vector<int>> &dp)
    {
        if(i == val.size()) return 0;

        if(dp[i][W] != -1)
        {
            return dp[i][W];
        }
        if(wt[i] > W)
        {
            return dp[i][W] = helper(i+1, val, wt, W, dp);
        }
        int c1 = val[i] + helper(i + 1, val, wt, W - wt[i], dp);
        int c2 = helper(i + 1, val, wt, W, dp);

        return dp[i][W] = max(c1, c2);

    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
        return helper(0, val, wt, W, dp);
    }
};
