// Leetcode Problem no 1679. Max Number of K-Sum Pairs
// Time Complexity: O(nlogn) + O(n) = O(nlogn)
// Space Complexity: O(1)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.size() - 1;
        int counter = 0;
        while(low < high)
        {
            // 2 3 4 5 6 7
            if(nums[low] + nums[high] == k)
            {
                counter++;
                low++;
                high--;
            }
            else if(nums[low] + nums[high] < k)
            {
                low++;
            }
            else if(nums[low] + nums[high] > k)
            {
                high--;
            }
        }

        return counter;
    }
};
