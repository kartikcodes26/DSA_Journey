// Problem no: 2962. Count Subarrays Where Max Element Appears at Least K Times
// Problem Link: https://leetcode.com/problems/count-subarrays-with-maximum-bitwise-or/description/
// TC : O(n) where n is the size of the array
// SC : O(1)
// difficulty : Medium
// Pattern : Sliding Window


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = *max_element(nums.begin(), nums.end());

        int low = 0;
        int high = 0;
        int maxcount = 0;
        long long int res = 0;

        while(high < nums.size())
        {
            if(nums[high] == maxele)
            {
                maxcount++;
            }

            // While valid
            while(maxcount >= k)
            {
                if(nums[low] == maxele)
                {
                    maxcount--;
                }

                low++;
            }

            // The amount of times we incremented low is the amount of subarrays that were valid
            // Because we are only incrementing when subarray is valid
            // thus low tells the number of valid subarrays
            res += low;

            high++;
        }
        return res;
    }
};
