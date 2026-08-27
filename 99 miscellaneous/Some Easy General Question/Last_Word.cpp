// Leetcode problem no : 58. Length of Last Word
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.
// Example 1:
// Input: s = "Hello World"
// Output: 5
// Time Complexity: O(n) where n is the length of the input string
// Space Complexity: O(1)

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        // Skip trailing spaces
        while(s[i] == ' ')
        {
            i--;
        }

        int res = 0;
        while(i >= 0 && s[i] != ' ')
        {
            res++;
            i--;
        }

        return res;
    }
};
