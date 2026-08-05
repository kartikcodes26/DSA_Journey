// Leetcode Problem No : 409. Longest Palindrome
// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.
// Time Complexity: O(n) where n is the length of s
// Space Complexity: O(n) where n is the length of s
// Difficulty: Easy
// Topic: HashMaps

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int res = 0;
        
        for(auto c : s)
        {
            mp[c]++;
            if(mp[c] % 2 == 0) // Pair formed
            {
                res += 2; // Pair means 2 characters
            }
        }

        for(auto c : s)
        {
            if(mp[c] % 2 != 0)  // Odd count means we can place one character in the middle of the palindrome
            {
                res++;
                break;
            }

        }

        return res;
    }
};
