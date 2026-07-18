

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        int res = INT_MIN;
        int zeroC = 0;

        for(high = 0; high < nums.size(); high++)
        {
            if(nums[high] == 0)
            {
                zeroC++;
            }

            while(zeroC > k)
            {
                low++;
                if(nums[low - 1] == 0)
                {
                    zeroC--;
                }
            }

            res = max(res, high - low + 1);
        }

        return res;
    }
};
