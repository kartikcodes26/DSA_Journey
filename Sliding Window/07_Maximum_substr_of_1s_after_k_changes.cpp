// Leetcode problem no 1004. Max Consecutive Ones III
// problem statement: Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Time Complexity: O(n)
// Space Complexity: O(1)
// Sliding Window Approach Variable

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int res = INT_MIN;
        int zeroC = 0;

        for(high = 0; high < nums.size(); high++)
        {
            if(nums[high] == 0)
            {
                zeroC++;
            }

            while(zeroC > k)
            {
                low++;
                if(nums[low - 1] == 0)
                {
                    zeroC--;
                }
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};
