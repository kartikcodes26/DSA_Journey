// Leetcode problem no: 55
// Link : https://leetcode.com/problems/jump-game/
// difficulty : Medium
// Pattern : Greedy
// TC : O(n) where n is the number of elements in the array
// SC : O(1) as we are not using any extra space
class Solution {

public:
    bool canJump(vector<int>& nums) {

        int curr = 0;

        for(auto num : nums)
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
