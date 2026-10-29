// Leetcode 2161. Partition Array According to Given Pivot
// Link : https://leetcode.com/problems/partition-array-according-to-given-pivot/
// TC : O(n) SC: O(n)
// difficulty : Medium
// pattern : Two Pointer


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> res(n);

        int i = 0;
        int j = n - 1;

        int i2 = 0;
        int j2 = n - 1;

        while(i < n && j >= 0)
        {
            if(nums[i] == pivot)
            {
                i++;
                continue;
            }
            if(nums[j] == pivot)
            {
                j--;
                continue;
            }
            if(nums[i] < pivot)
            {
                res[i2] = nums[i];
                i2++;
            }
            if(nums[j] > pivot)
            {
                res[j2] = nums[j];
                j2--;
            }

            i++;
            j--;
        }

        for(int k = i2; k <= j2; k++)
        {
            res[k] = pivot;
        }

        return res;
    }
};
