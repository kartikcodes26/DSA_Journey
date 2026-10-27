// leetcode 16. 3Sum Closest
// link : https://leetcode.com/problems/3sum-closest/
// TC : O(n^2) SC: O(1)
// difficulty : Medium
// pattern : Two Pointer, threepointer

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int leastDistSum = INT_MAX;
        int leastDist = INT_MAX;

        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k)
            {
                int currSum = nums[i] + nums[j] + nums[k];
                int currdist = abs(currSum - target);
                if(currdist < leastDist)
                {
                    leastDistSum = currSum;
                    leastDist = currdist;
                }
                if(currSum == target)
                {
                    return leastDistSum;
                }
                else if(currSum < target)
                {
                    j++;
                }
                else if(currSum > target)
                {
                    k--;
                }
            }
        }

        return leastDistSum;
    }
};
