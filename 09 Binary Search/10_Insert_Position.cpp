// Leetcode 35. Search Insert Position
// Link: https://leetcode.com/problems/search-insert-position/
// Time Complexity: O(log n), where n is the length of the vector nums.
// Space Complexity: O(1), as we are using a constant amount of space to store the result and the temporary variables.
// Difficulty: Easy

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
