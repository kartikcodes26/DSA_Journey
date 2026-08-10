// Leetcode Problem No 875. Koko Eating Bananas
// description: Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead, and will not eat any more bananas during this hour.
// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards come back.
// Return the minimum integer k such that she can eat all the bananas within h hours.
// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile
// Space Complexity: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // We pretend an array of possible speeds exist
        // lowest speed is low
        // high = max number of banana stacks
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int k;
        bool ispossible = true;
        int res = high;

        while(low <= high)
        {
            int i = 0;
            long long hours = 0;
            ispossible = true;
            int mid = low + (high - low) / 2;
            k = mid; // Make the search space itself be the possible speeds
            
            while(i < piles.size())
            {
                if(piles[i] % k != 0)
                {
                    hours += (piles[i] / k) + 1;
                }
                else
                {
                    hours += (piles[i] / k);
                }
                if(hours > h)
                {
                    low  = mid + 1;
                    ispossible = false;
                    break;
                }
                i++;
            }
            if(ispossible)
            {
                res = k;
                high = mid - 1;
            }

        }
        return res;
    }
};
