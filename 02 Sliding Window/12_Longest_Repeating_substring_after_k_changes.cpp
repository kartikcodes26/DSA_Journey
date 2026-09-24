// leetcode 424. Longest Repeating Character Replacement
// link : https://leetcode.com/problems/longest-repeating-character-replacement/
// TC : O(n) where n is the size of the string
// SC : O(26) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int low = 0;
        int high = 0;
        int maxf = 0;
        int res = 0;
        unordered_map<char, int> mp;

        // to_change = current subarray ka size - majority elements = minority elements we need to change
        // to_change = (high - low + 1) - maxf
        for(high = 0; high < s.size(); high++)
        {
            mp[s[high]]++;
            maxf = max(maxf, mp[s[high]]); // record majority element
            int to_change = (high - low + 1) - maxf;

            // While window is invalid
            while(to_change > k)
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                {
                    mp.erase(s[low]);
                }
                low++;
                to_change = (high - low + 1) - maxf;
            }

            // Now that the window is valid, Store max size result
            res = max(res, (high - low + 1));
        }
        return res;
    }
};
