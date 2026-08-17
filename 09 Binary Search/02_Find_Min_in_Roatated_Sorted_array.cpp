// Leetcode 153. Find Minimum in Rotated Sorted Array
// description: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. Given the sorted rotated array nums of unique elements, return the minimum element of this array.
// example: Input: nums = [3,4,5,1,2] Output: 1
// Difficulty: Medium
// Required time complexity: O(log n)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Asked in interviews: Amazon, Microsoft, Google, Facebook, Adobe, Oracle, Walmart, Cisco, Bloomberg, PayPal

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        int res;
        // 1 2 3 4 5
        // 5 1 2 3 4
        // 4 5 1 2 3
        // 3 4 5 1 2
        // 2 3 4 5 1
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(arr[mid] > arr[arr.size() - 1])
            {
                low = mid + 1;
            }
            else if(arr[mid] <= arr[arr.size() - 1])
            {
                res = mid;
                high = mid - 1;
            }
        }

        return arr[res];
    }
};
