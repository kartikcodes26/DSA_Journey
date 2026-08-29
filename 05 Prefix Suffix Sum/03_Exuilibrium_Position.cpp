// Leetcode 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/
// Difficulty: Easy
// TC : O(n)
// SC : O(1)
//pattern : Prefix Sum + Suffix Sum

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        // ps + ss + arr[i] = total
        for(int i = 0; i < nums.size(); i++)
        {
            int right = total - left - nums[i]; // Left 0 ke liye already calculate ho chuka hai
            if(left == right)
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};
