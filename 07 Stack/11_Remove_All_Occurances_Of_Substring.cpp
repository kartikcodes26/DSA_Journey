// Leetcode Problem: 1910. Remove All Occurrences of a Substring
// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Time Complexity: O(n * m), where n is the length of the string s and m is the length of the substring part.
// space Complexity: O(n), where n is the length of the string s.
// Description: Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed: Find the leftmost occurrence of the substring part and remove it from s. Return s after removing all occurrences of part. It is guaranteed that the answer is unique.
// Example 1:
// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Example 2:
// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Difficulty: Medium

class Solution {
public:
    string removeOccurrences(string s, string part) {
        string res = "";
        int i = 0;
        while(i < s.size())
        {
            res.push_back(s[i]);
            if(res.size() >= part.size())
            {
                if(res.substr(res.size() - part.size()) == part)
                {
                    res.erase(res.size() - part.size(), part.size());
                }
            }

            i++;
        }

        return res;
    }
};
