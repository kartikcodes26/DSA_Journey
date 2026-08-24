// Leetcode 7. Reverse Integer
// Link: https://leetcode.com/problems/reverse-integer/
// Time Complexity: O(log10(x)), where x is the input integer. The number of digits in x is log10(x).
// Space Complexity: O(1), as we are using a constant amount of space to store the result and the temporary variables.
// Description: Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Example 1: Input: x = 123, Output: 321
// Example 2: Input: x = -123, Output: -321
// Example 3: Input: x = 120, Output: 21
// Difficulty: Medium

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int temp = x;
        while(temp != 0)
        {
            int digit = temp % 10;
            if(res * 10 > INT_MAX || res * 10 < INT_MIN)
            {
                return 0;
            }
            res = res * 10 + digit;
            temp = temp / 10;
        }
        return res;
    }
};
