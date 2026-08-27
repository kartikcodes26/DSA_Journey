// Leetcode problem no : 66. Plus One
// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.
// Example 1:
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Time Complexity: O(n) where n is the number of digits in the input array
// Space Complexity: O(1) if we don't consider the output array, otherwise O(n) for the output array.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if(digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            else
            {
                digits[i] = 0;
            }
        }

        // Ek bhi baar return nahi hua matalb sare digits 9 the, toh sab abhi zero ho gaye hoge, bas starting me ek 1 lagana hai

        digits.insert(digits.begin(), 1); // (iterator, value)

        return digits;
    }
};
