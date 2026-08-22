// LeetCode: 509. Fibonacci Number
// https://leetcode.com/problems/fibonacci-number/
// Problem Statement: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// Time Complexity: O(2^n) - Exponential time complexity due to the recursive calls.
// Space Complexity: O(n) - The maximum depth of the recursion tree can go up to n.
// Difficulty: Easy

class Solution {
public:
    int fib(int n) {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
