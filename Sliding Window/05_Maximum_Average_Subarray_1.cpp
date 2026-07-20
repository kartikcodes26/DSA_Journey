// Leetcode 643. Maximum Average Subarray I
// Time Complexity: O(n)
// Space Complexity: O(1)
// Sliding Window Approach fixed
// Problem statement: Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.



class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = k - 1;  // The first k elements will be the initial window
        double sum = 0;
        double res = INT_MIN;

        for(int i = 0; i <= high; i++) // Calculate the sum of the first k elements
        {
            sum += nums[i];
        }

        while(high < nums.size())
        {
            res = max(sum, res); // Update the maximum sum found so far
            low++;
            high++;
            sum -= nums[low - 1]; // Remove the element going out of the window

            if(high != nums.size()) // To avoid going out of bounds
            {
                sum += nums[high];  // Add the new element coming into the window
            }

        }

        return res / k; // Return the maximum average
    }
};
