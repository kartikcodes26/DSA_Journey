// Leetcode 1189. Maximum Number of Balloons
// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
// You can use each character in text at most once. Return the maximum number of instances that can be formed.
// Time Complexity: O(n) where n is the length of text
// Space Complexity: O(n) where n is the length of text
// Difficulty: Easy

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        int counter = 0;
        unordered_map<char, int> mp2;

        for(auto d : text)
        {
            mp2[d]++;
        }
        /*
        b 1
        a 1
        l 2
        o 2
        n 1
        s 1
        */
        while(true)
        {
            for(auto ele : s)
            {
                if(mp2[ele] == 0) return counter;
                mp2[ele]--;
            }
            counter++;
        }

        return counter;

    }
};
