// Leetcode 9. Palindrome Number
// Link: https://leetcode.com/problems/palindrome-number/
// Time Complexity: O(log10(x)), where x is the input integer. The number of digits in x is log10(x).
// Space Complexity: O(1), as we are using a constant amount of space to store the result and the temporary variables.
// Description: Given an integer x, return true if x is palindrome integer.
// An integer is a palindrome when it reads the same backward as forward. For example, 121 is a palindrome while 123 is not.
// Example 1: Input: x = 121, Output: true
// Example 2: Input: x = -121, Output: false
// Explanation: From left to right, it reads -121. From right to left, it
// reads 121-. Therefore it is not a palindrome.
// Difficulty: Easy

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int temp = x;
        long long rDigit = 0;

        while(temp != 0)
        {
            long long digit = temp % 10;
            rDigit = rDigit * 10 + digit;
            temp = temp / 10;
        }

        if(x == rDigit) return true;
        else return false;
    }
};
