// Leetcode Problem: 567. Permutation in String
// Problem Statement: Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise. In other words, return true if one of s1's permutations is the substring of s2.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Fixed Sliding window approach
        if (s1.size() <= s2.size())
        {

            unordered_map<char, int> mp1;
            unordered_map<char, int> mp2;

            int i = 0;
            int j = s1.size() - 1;

            for (int b = 0; b < s1.size(); b++) {
                mp1[s1[b]]++;
            }
            for (int a = i; a <= j; a++) {
                mp2[s2[a]]++;
            }

            while (j < s2.size()) {
                if (mp1 == mp2) {
                    return true;
                }
                i++;
                j++;
                if (j == s2.size())
                    break;
                mp2[s2[j]]++;
                mp2[s2[i - 1]]--;
                if (mp2[s2[i - 1]] == 0) {
                    mp2.erase(s2[i - 1]);
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
};
