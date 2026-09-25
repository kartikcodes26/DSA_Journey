// Leetcode 930. Binary Subarrays With Sum
// link : https://leetcode.com/problems/binary-subarrays-with-sum/
// TC : O(n) where n is the size of the array
// SC : O(1) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int atmostgoal(vector<int>& nums, int goal)
    {
       if(goal < 0) return 0;
       int low = 0;
       int high = 0;
       int res = 0;
       int sum = 0;

       while(high < nums.size())
       {
        sum += nums[high];

        while(sum > goal)
        {
            sum -= nums[low];
            low++;
        }

        res += high - low + 1;
        high++;
       }

       return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostgoal(nums, goal) - atmostgoal(nums, goal - 1);
    }
};
