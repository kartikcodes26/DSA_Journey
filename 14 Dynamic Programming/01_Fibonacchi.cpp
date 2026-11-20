// Leetcode 509. Fibonacci Number (DP approach)
// link : https://leetcode.com/problems/fibonacci-number/
// TC : O(n) SC: O(n)
// difficulty : Easy
// pattern : Dynamic Programming
// Approach : Memoization

class Solution {
public:
    unordered_map<int, int> dp;
    int fib(int n) {
        if(n == 0 || n == 1)
        {
            return n;
        }
        if(dp.find(n) != dp.end())
        {
            return dp[n];
        }
        int ans = fib(n - 1) + fib(n - 2);

        dp[n] = ans;

        return ans;
    }
};
