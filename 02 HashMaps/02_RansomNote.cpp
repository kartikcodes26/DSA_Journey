// Leetcode 383. Ransom Note
// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
// Each letter in the magazine string can only be used once in your ransom note.
// Time Complexity: O(n +m) where n is the length of ransomNote and m is the length of magazine
// Space Complexity: O(n + m) where n is the length of ransomNote and m is the length of magazine
// Difficulty: Easy

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(auto c : ransomNote)
        {
            mp1[c]++;
        }
        for(auto d : magazine)
        {
            mp2[d]++;
        }

        for(auto ele : mp1)
        {
            if(mp1[ele.first] > mp2[ele.first])
            {
                return false;
            }
        }

        return true;
    }
};
