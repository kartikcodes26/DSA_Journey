// Leetcode 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Link : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// TC : O(nlogn) SC: O(n)
// difficulty : Medium
// pattern : Two Pointer, Bit Manipulation

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int mod = 1e9 + 7;
        int i = 0;
        int j = nums.size() - 1;
        int res = 0;

        vector<int> power(nums.size(), 1);

        // precomputing powers of two
        for (int k = 1; k < nums.size(); k++) {
            power[k] = (2LL * power[k - 1]) % mod;
        }

        while(i <= j)
        {
            if(nums[i] + nums[j] <= target)
            {
                res = (res + power[j - i]) % mod; // will learn in bitwise
                i++;
            }
            else
            {
                j--;
            }
        }

        return res;
    }
};
