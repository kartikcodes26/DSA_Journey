// Leetcode 13. Roman to Integer
// Link: https://leetcode.com/problems/roman-to-integer/
// Time Complexity: O(n), where n is the length of the string s.
// Space Complexity: O(1), as we are using a constant amount of space to store the result and the temporary variables.
// DIfficulty: Easy

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
