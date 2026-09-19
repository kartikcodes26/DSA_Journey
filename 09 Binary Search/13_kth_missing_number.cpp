// Leetcode 1539. Kth Missing Positive Number
// link : https://leetcode.com/problems/kth-missing-positive-number/
// TC : O(log n) where n is the size of the array
// SC : O(1) since we are using constant space for the pointers
// Difficulty : Easy
// Pattern : Binary Search


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] - mid - 1 < k) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};
