// Leetcode 1793. Maximum Score of a Good Subarray
// link : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
// TC : O(n) SC: O(1)
// difficulty : Medium
// pattern : Sliding Window, Two Pointer           

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k;
        int right = k;

        int minVal = nums[k];
        int res = minVal;

        int n = nums.size();

        while(left > 0 || right < n - 1)
        {
            if(left == 0)
            {
                right++;
                minVal = min(minVal, nums[right]);
            }
            else if(right == n - 1)
            {
                left--;
                minVal = min(minVal, nums[left]);
            }
            else if(nums[left - 1] > nums[right + 1])
            {
                left--;
                minVal = min(minVal, nums[left]);
            }
            else
            {
                right++;
                minVal = min(minVal, nums[right]);
            }

            res = max(res, minVal * (right - left + 1));
        }

        return res;
    }
};
