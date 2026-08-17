// Leetcode 125. Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size();)
        {
           if(!isalnum(s[i]))
           {
               s.erase(i, 1);
           }
           else
           {
               i++;
           }
        }

        int start = 0;
        int end = s.size() - 1;
        bool ispalindrome = true;

        while(start < end)
        {
            if(tolower(s[start]) != tolower(s[end]))
            {
                ispalindrome = false;
                break;
            }
            start++;
            end--;
        }

        return ispalindrome;
    }
};

// Time Complexity : O(2n)
// Space Complexity : O(1)
