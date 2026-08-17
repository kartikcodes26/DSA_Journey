// Leetcode 162. Find Peak Element
// description: A peak element is an element that is strictly greater than its neighbors. Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
// You may imagine that nums[-1] = nums[n] = -∞.
// example: Input: nums = [1,2,3,1] Output: 2
// Required time complexity: O(log n)
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Asked in interviews: Amazon, Microsoft, Google, Facebook, Adobe, Oracle, Walmart, Cisco, Bloomberg, PayPal
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int low = 0;
        int high = nums.size() - 1;
        // 4 3 2 1
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mid < nums.size() - 1 && nums[mid + 1] > nums[mid])
            {
                low = mid + 1;
            }
            else if(mid > 0 && nums[mid - 1] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};
