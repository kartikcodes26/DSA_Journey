// leetcode 1493. Longest Subarray of 1's After Deleting One Element
// Time Complexity: O(n)
// Space Complexity: O(1)
// Sliding Window Approach Variable

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int low = 0;
        int high = 0;
        int res = INT_MIN;
        int zeroC = 0;

        for (high = 0; high < nums.size(); high++) {
            if (nums[high] == 0) {
                zeroC++;
            }

            while (zeroC > 1) {
                low++;
                if (nums[low - 1] == 0) {
                    zeroC--;
                }
            }
            if(zeroC == 1)
            {
                res = max(res, high - low + 1 - 1);
            }
        }
        if(zeroC == 0)
        {
            return nums.size() - 1;
        }
        return res;
    }
};
