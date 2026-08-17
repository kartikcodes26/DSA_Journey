// Leetcode problem no 53. Maximum Subarray
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// time complexity is O(n) and space complexity is O(1)
// difficulty level is medium

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadanes Algorithm

        int sum = 0;
        int res = INT_MIN;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0)
            {
                sum = 0;
            }
        }

        return res;
    }
};
