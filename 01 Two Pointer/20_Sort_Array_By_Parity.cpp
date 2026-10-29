// leetcode 905. Sort Array By Parity
// link : https://leetcode.com/problems/sort-array-by-parity/
// TC : O(n) SC: O(n)
// difficulty : Easy
// pattern : Two Pointer

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int i2 = 0, j2 = nums.size() - 1;
        vector<int> res(nums.size());
        while(i < nums.size())
        {
            if(nums[i] % 2 == 0)
            {
                res[i2] = nums[i];
                i2++;
            }
            if(nums[j] % 2 != 0)
            {
                res[j2] = nums[j];
                j2--;
            }
            i++;
            j--;
        }

        return res;
    }
};
