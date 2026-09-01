// leetcode 17. Letter Combinations of a Phone Number
// link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// TC = O(4^n * n), SC = O(n) where n is the length of the digits string
// Difficulty: Medium, personal difficulty: Hard

class Solution {
public:
    void helper(string digits, int n, int idx, unordered_map<char, string> mp, string &tmp, vector<string> &res)
    {
        if(idx == n)
        {
            res.push_back(tmp);
            return ;
        }

        string choice = mp[digits[idx]];
        for(int j = 0; j < choice.size(); j++)
        {
            tmp.push_back(choice[j]);
            helper(digits, n, idx + 1, mp, tmp, res);
            tmp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        unordered_map<char, string> mp;
        string tmp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        helper(digits, digits.size(), 0, mp, tmp, res);
        return res;
    }
};
