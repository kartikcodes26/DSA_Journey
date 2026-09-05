// Leetcode 46. Permutations
// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
// TC = O(n! * n) where n is the length of the input array
// SC = O(n) for recursion stack
// Difficulty: Medium
// Pattern: Backtracking

class Solution {
public:
    void helper(vector<int> nums, int idx, vector<vector<int>> &res)
    {
        if(idx == nums.size())
        {
            res.push_back(nums);
            return ;
        }

        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[idx], nums[i]); // Swap
            helper(nums, idx + 1, res); // go ahead and explore all possibilities
            swap(nums[idx], nums[i]); // Undo
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;

        helper(nums, 0, res);
        return res;
    }
};
