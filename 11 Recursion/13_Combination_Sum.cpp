// Leetcode 39. Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
// Time Complexity: O(2^n), where n is the length of the vector candidates. In the worst case, we may have to explore all possible combinations of candidates.
// Space Complexity: O(n), where n is the length of the vector candidates. In the worst case, we may have to store all candidates in the temporary vector temp.
// Difficulty: Medium

class Solution {
public:
    void helper(vector<int> &v, int i, vector<vector<int>> &res, int target, vector<int> temp)
    {
        if(target == 0) // Agar kisi bhi point pe target zero ho jaye
        {
            res.push_back(temp); // wo sequence ko save karlo
            return ; // piche aa jao
        }
        if(target < 0 || i > v.size() - 1) // agar target negative ho jaye ya i out of bounds chale jaye
        {
            return ; // Piche aa jao, aage nahi jaa sakte
        }

        temp.push_back(v[i]); // take
        helper(v, i, res, target - v[i], temp); // try the same element
        temp.pop_back(); // Not take
        helper(v, i+1, res, target, temp); // Try the next element
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(candidates, 0, res, target, temp);

        return res;
    }
};
