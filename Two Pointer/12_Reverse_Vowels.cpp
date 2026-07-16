// Leetcode 345. Reverse Vowels of a String

class Solution {
public:
    bool isvowel(char c) {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }

        return false;
    }


    string reverseVowels(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(start < end)
        {
            if(!isvowel(s[start]))
            {
                start++;
                continue;
            }
            if(!isvowel(s[end]))
            {
                end--;
                continue;
            }

            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};

// Time Complexity : O(n)
// Space Complexity : O(1)
