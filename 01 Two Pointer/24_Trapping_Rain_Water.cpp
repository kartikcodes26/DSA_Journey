// Leetcode 42. Trapping Rain Water
// link : https://leetcode.com/problems/trapping-rain-water/
// TC : O(n) SC: O(n)
// difficulty : Hard
// pattern : Two Pointer, Array
// Approach : 1. Find the left max and right max for each index

class Solution {
public:
    vector<int> getLeftMax(vector<int> height, int n)
    {
        vector<int> res(n);
        res[0] = height[0];

        for(int i = 1; i < n; i++)
        {
            res[i] = max(res[i - 1], height[i]);
        }

        return res;
    }

    vector<int> getRightMax(vector<int> height, int n)
    {
        vector<int> res(n);
        res[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i--)
        {
            res[i] = max(res[i + 1], height[i]);
        }

        return res;
    }

    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        for(int i = 0; i < height.size(); i++)
        {
            int h = min(leftMax[i], rightMax[i]) - height[i];
            sum += h;
        }

        return sum;
    }
};
