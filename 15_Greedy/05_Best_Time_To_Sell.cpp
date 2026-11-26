// Leetcode problem no : 121
// difficulty: Easy
// TC : O(n)
// SC : O(1)
// link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Approach: Greedy

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue = INT_MAX;
        int maxProfit = INT_MIN;

        for(int i = 0; i < prices.size(); i++)
        {
            minValue = min(minValue, prices[i]);
            int profit = prices[i] - minValue;
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
};
