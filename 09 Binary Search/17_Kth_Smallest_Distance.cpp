// Leetcode 719. Find K-th Smallest Pair Distance
// link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/
// TC : O(nlogn + nlog(max-min)) SC: O(1)
// difficulty : Hard
// pattern : Binary Search, Two Pointer

class Solution {
public:
    bool ispossible(vector<int>& nums, int mid,int k) {
        int j = 0, count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(j < n && nums[j] - nums[i] <= mid)
            {
                j++;
            }
            count += j - i - 1;
        }

        return count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());


        int left = 0;
        int right = nums[nums.size() - 1] - nums[0];
        int res = 0;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(ispossible(nums, mid, k)) {
                res = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return res;
    }
};
