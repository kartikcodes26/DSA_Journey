// Leetcode problem no 340. Longest Substring with K Distinct Characters
// problem statement: Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        unordered_map<char,int> mp;
        int low = 0;
        int res = 0;

        for(int high = 0; high < s.size(); high++)
        {
            mp[s[high]]++;
            while(mp.size() > k)
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                {
                    mp.erase(s[low]);
                }
                low++;
            }
            if(mp.size() <= k)
            {
                res = max(res, high - low + 1);
            }
        }

        return res;


    }
};
