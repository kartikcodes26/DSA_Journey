// Leetcode 11. Container With Most Water
// time complexity : O(n)
// space complexity : O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {

        int max = 0;

        int i = 0;
        int j = height.size() - 1;

        int result;

        while (i < j) {
            if (height[i] > height[j]) {
                result = height[j] * (i - j);
                j--;
            } else if (height[i] < height[j]) {
                result = height[i] * (i - j);
                i++;
            } else { //Equal case
                result = height[i] * (i - j);
                i++;
            }

            if (result > max) {
                max = result;
            }

        }

        return max;
    }
};
