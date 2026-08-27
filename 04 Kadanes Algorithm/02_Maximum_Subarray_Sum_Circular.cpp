// Leetcode problem no : 918. Maximum Sum Circular Subarray
// Link : https://leetcode.com/problems/maximum-sum-circular-subarray/
// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
// Example 1:
// Input: nums = [1,-2,3,-2]
// Output: 3
// Time Complexity: O(n) where n is the number of elements in the input array
// Space Complexity: O(1)
// Difficulty: Medium

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // 1 Element hona hii chaiye
        int gmax = nums[0];
        int cmax = nums[0];
        int gmin = nums[0];
        int cmin = nums[0];
        int total = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            total += nums[i];
            cmax = max(cmax + nums[i], nums[i]);
            cmin = min(cmin + nums[i], nums[i]);
            gmin = min(cmin, gmin);
            gmax = max(cmax, gmax);

        }
        int res;
        if(gmax >= 0)
        {
            res = max(total - gmin, gmax);
        }
        else
        {
            res = gmax;
        }

        return res;
    }
};
