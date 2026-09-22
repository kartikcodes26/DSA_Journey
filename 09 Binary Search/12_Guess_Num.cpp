// Leetcode 374. Guess Number Higher or Lower
// link : https://leetcode.com/problems/guess-number-higher-or-lower/
// TC : O(log n) where n is the number of guesses
// SC : O(1) since we are using constant space for the pointers
// Difficulty : Easy
// Pattern : Binary Search

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(guess(mid) == 0) return mid;
            else if(guess(mid) == 1) low = mid + 1;
            else high = mid - 1;
        }
        return 1; // useless;
    }
};
