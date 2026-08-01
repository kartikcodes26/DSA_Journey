// Leetcode problem no: 387. First Unique Character in a String
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Easy

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for(auto c : s)
        {
            mp[c]++;
        }

        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
