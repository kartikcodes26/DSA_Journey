// leetcode 904. Fruit Into Baskets
// link : https://leetcode.com/problems/fruit-into-baskets/
// TC : O(n) where n is the size of the array
// SC : O(2) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int high = 0;
        int res = 0;
        unordered_map<int, int> mp;

        while(high < fruits.size())
        {
            mp[fruits[high]]++;

            // while invalid
            while(mp.size() > 2) // Only 2 baskets are available
            {
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0)
                {
                    mp.erase(fruits[low]);
                }
                low++;
            }

            // now the subarray is valid
            res = max(res, high - low + 1);
            high++;
        }
        return res;
    }
};
