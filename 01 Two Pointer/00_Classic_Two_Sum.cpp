// Leetcode 1. Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Time Complexity: O(n), where n is the length of the array nums.
// Space Complexity: O(n), as we are using a hash map to store the elements of
// the array nums.
// Description: Given an array of integers nums and an integer target, return indices of the two
// Different numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.
// Difficulty: Easy

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++)
        {
            int needed = target - nums[i];

            if(mp.find(needed) != mp.end())
            {
                return {mp[needed], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};
