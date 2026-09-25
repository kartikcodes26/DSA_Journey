// Leetcode 1248. Count Number of Nice Subarrays
// link : https://leetcode.com/problems/count-number-of-nice-subarrays/
// TC : O(n) where n is the size of the array
// SC : O(1) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int atmostkodd(vector<int>& nums, int k)
    {
        int low = 0;
        int high = 0;
        int oddc = 0;
        int res = 0;

        while(high < nums.size())
        {
            // add element
            if(nums[high] % 2 != 0) oddc++;

            // While not valid
            while(oddc > k)
            {
                if(nums[low] % 2 != 0) oddc--;
                low++;
            }

            // valid
            res += high - low + 1;

            high++;

        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostkodd(nums, k) - atmostkodd(nums, k-1);
    }
};
