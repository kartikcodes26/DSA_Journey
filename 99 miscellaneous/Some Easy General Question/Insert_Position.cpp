// Leetcode problem no : 35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.
// Time Complexity: O(log n) where n is the number of elements in the input array
// Space Complexity: O(1)
// DIfficulty: Easy


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        int res = INT_MAX;
        while(i <= j)
        {
            int mid = (i + j) / 2;
            if(target <= nums[mid])
            {
                j = mid - 1;
                res = mid;
            }
            else
            {
                i = mid + 1;
            }
        }
        if(res == INT_MAX)
        {
            return nums.size();
        }
        return res;
    }
};
