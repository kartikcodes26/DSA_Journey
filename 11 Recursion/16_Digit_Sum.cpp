// gfg problem name : Sum of digits
// gfg link : https://practice.geeksforgeeks.org/problems/sum-of-digits-of-a-given-number/0
// Difficulty: Easy
// TC : O(log n)
// SC : O(log n) (recursion stack space)
// Pattern : Recursion

class Solution {
  public:
    int sumOfDigits(int n, int sum = 0) {
        // Base case
        if(n == 0)
        {
            return sum;
        }

        // Work
        sum += n % 10;
        n = n / 10;

        // Move forward
        sumOfDigits(n, sum);

    }
};
