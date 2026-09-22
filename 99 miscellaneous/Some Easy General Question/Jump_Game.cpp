// Problem No: 55
// Problem Name: Jump Game
// Problem Link: https://leetcode.com/problems/jump-game/
// Difficulty: Medium
// Pattern: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int curr = 0;

        for (auto num : nums)
        {
            if (curr < 0)
            {
                return false;
            }

            if (num > curr)
            {
                curr = num;
            }

            curr--;
        }

        return true;
    }
};