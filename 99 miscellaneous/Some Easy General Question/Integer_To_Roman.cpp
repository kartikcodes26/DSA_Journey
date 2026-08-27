// Leetcode problem no : 12. Integer to Roman
// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.
// Example 1:
// Input: 3
// Output: "III"
//Time Complexity: O(n) where n is the number of digits in the input number
// Space Complexity: O(1)
// Difficulty: Easy

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string res = "";
        int i = 0;
        while(num > 0)
        {
            int digit = num / mp[i].first;
            while(digit > 0)
            {
                res += mp[i].second;
                digit--;
            }
            num = num % mp[i].first;
            i++;
        }

        return res;
    }
};
