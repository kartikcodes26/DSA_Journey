// Leetcode Problem: 1208. Get Equal Substrings Within Budget
// link : https://leetcode.com/problems/get-equal-substrings-within-budget/
// TC : O(n) where n is the size of the array
// SC : O(1) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currcost = 0;
        int low = 0;
        int high = 0;
        int res = 0;
        while(high < s.size())
        {
            currcost += abs(s[high] - t[high]);

            // Invalid
            while(currcost > maxCost)
            {
                currcost -= abs(s[low] - t[low]);
                low++;
            }

            // valid
            res = max(res, high - low + 1);
            high++;
        }
        return res;
    }
};
