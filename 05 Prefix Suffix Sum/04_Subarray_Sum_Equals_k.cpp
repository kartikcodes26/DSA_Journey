// Leetcode 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/
// Difficulty: Medium
// TC : O(n)
// SC : O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = nums[0];
        mp[sum]++;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int ques = sum - k;
            int freq = mp[ques];
            res += freq;
            mp[sum]++;
        }
        return res;
    }
};
