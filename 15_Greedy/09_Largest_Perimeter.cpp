// Leetcode 976. Largest Perimeter Triangle
// Link : https://leetcode.com/problems/largest-perimeter-triangle/
// Difficulty : Easy
// TC : O(nlogn)
// SC : O(1)
// Approach : Greedy

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int> ());
        for(int i = 0; i <= nums.size() - 3; i++)
        {
            if(nums[i] < nums[i + 1] + nums[i + 2])
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
