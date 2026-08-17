// Leetcode Problem No 33. Search in Rotated Sorted Array
// description: There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
// Required time complexity: O(log n)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Difficulty: Medium
// Asked in interviews: Amazon, Microsoft, Google, Facebook, Adobe, Oracle, Walmart, Cisco, Bloomberg, PayPal

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        // 8
        // 7 8 9 10 1 2 3 4 5 6
        while(low <= high)
        {
            int mid =low + (high - low) / 2; // Avoids integer overflow
            if(nums[mid] == target) return mid;
            // Part 1
            if(nums[mid] > nums[n - 1])
            {
                if(target > nums[mid])
                {
                    // shift right
                    low = mid + 1;
                }
                else
                {
                    if(nums[0] > target)
                    {
                        // Shift Right
                        low = mid + 1;
                    }
                    else
                    {
                        // Shift Left
                        high = mid - 1;
                    }
                }
            }
            // Part 2
            else
            {
                if(target > nums[mid])
                {
                    if(target <= nums[n - 1]) // '=' is important as the target can literally be at the end of the array
                    {
                        // Shift Right
                        low = mid + 1;
                    }
                    else
                    {
                        // Shift Left
                        high = mid - 1;
                    }
                }
                else
                {
                   high = mid - 1;
                }
            }
        }
        return -1;
    }
};
