// Leetcode problem: 22. Generate Parentheses
// link: https://leetcode.com/problems/generate-parentheses/
// TC: O(4^n / sqrt(n)) (Catalan number)
// SC: O(n) (recursion stack space)
// Difficulty: Medium
// Pattern: Recursion

class Solution {
public:
    vector<string> helper(int n,string& tmp, vector<string> &res, int open = 0, int close = 0) {
        if(open == n && close == n)
        {
            res.push_back(tmp);
            return res;
        }

        if(open < n)
        {
            tmp.push_back('(');
            helper(n, tmp, res, open + 1, close);
            tmp.pop_back();
        }

        if(close < open)
        {
            tmp.push_back(')');
            helper(n, tmp, res, open, close + 1);
            tmp.pop_back();
        }

        return res;
    }
    vector<string> generateParenthesis(int n) {
        string tmp = "";
        vector<string> res = {};
        return helper(n, tmp, res);
    }
};
