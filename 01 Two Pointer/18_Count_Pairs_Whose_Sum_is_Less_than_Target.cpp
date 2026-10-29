// Leetcode 2593. Count Pairs Whose Sum is Less than Target
// Link : https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
// TC : O(nlogn) SC: O(1)
// difficulty : Medium
// pattern : Two Pointer

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int count = 0;

        while(i < j)
        {
            if(nums[i] + nums[j] < target)
            {
                count += j - i;
                i++;
            }
            else
            {
               j--;
            }
        }

        return count;
    }
};
