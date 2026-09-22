// Leetcode 1011. Capacity To Ship Packages Within D Days
// link : https://leetcode.com/problems/capacity-to-ship-packages-within-d
// TC : O(n log m) where n is the size of the array and m is the sum of weights
// SC : O(1) since we are using constant space for the pointers
// Difficulty : Medium
// Pattern : Binary Search

class Solution {
public:
    bool ispossible(vector<int>& weights, int days, int capacity)
    {
        int tdays = 1;
        int currweights = 0;

        for(auto w : weights)
        {
            if(currweights + w > capacity)
            {
                tdays++;
                currweights = w;
            }
            else
            {
                currweights += w;
            }
        }

        return tdays <= days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(), weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int res = 0;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(ispossible(weights, days, mid))
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return res;
    }
};
