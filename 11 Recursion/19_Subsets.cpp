// leetcode 78. Subsets
// link: https://leetcode.com/problems/subsets/
// TC = O(2^n * n), SC = O(n) where n is the length of the nums vector
// Difficulty: Medium
// Pattern: Recursion, Backtracking

class Solution {
public:
    void helper(vector<int>& nums, int i,int n, vector<vector<int>> &res, vector<int> &tmp)
    {
        if(i == n)
        {
            res.push_back(tmp);
            return ;
        }

        tmp.push_back(nums[i]);
        helper(nums, i + 1, n, res, tmp);
        tmp.pop_back();
        helper(nums, i + 1, n, res, tmp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(nums, 0, nums.size(), res, tmp);

        return res;
    }
};
