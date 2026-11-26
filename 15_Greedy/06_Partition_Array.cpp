// Leetcode problem no : 561
// difficulty: Easy
// TC : O(nlogn)
// SC : O(1)
// link : https://leetcode.com/problems/array-partition/
// Approach: Greedy

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size(); i += 2)
        {
            res += nums[i];
        }
        return res;
    }
};
