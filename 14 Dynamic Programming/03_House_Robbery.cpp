// LeetCode 198. House Robber
// Link : https://leetcode.com/problems/house-robber/
// TC : O(n) SC: O(n)
// difficulty : Medium
// pattern : Dynamic Programming
// approach : Memoization

class Solution {
public:

    int helper(vector<int> &nums, int i, int free, vector<vector<int>> &dp)
    {
        if(i == nums.size())
        {
            return 0;
        }
        if(dp[i][free] != -1)
        {
            return dp[i][free];
        }
        if(free == 0)
        {
            return dp[i][free] = helper(nums, i + 1, 1, dp);
        }

        int c1 = nums[i] + helper(nums, i + 1, 0, dp);
        int c2 = helper(nums, i + 1, 1, dp);

        return dp[i][free] = max(c1, c2);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return helper(nums, 0, 1, dp);
    }
};
