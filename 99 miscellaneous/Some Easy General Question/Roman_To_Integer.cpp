// Leetcode problem no : 13. Roman to Integer
// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.
// Example 1:
// Input: s = "III"
// Time Complexity: O(n) where n is the number of characters in the input string
// Space Complexity: O(1)
// Difficulty: Easy

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i != s.size() - 1 && mp[s[i]] >= mp[s[i + 1]])
            {
                res += mp[s[i]];
            }
            else if (i != s.size() - 1 && mp[s[i]] < mp[s[i + 1]])
            {
                res -= mp[s[i]];
            }
            else
            {
                res += mp[s[i]];
            }
        }

        return res;
        }
};
