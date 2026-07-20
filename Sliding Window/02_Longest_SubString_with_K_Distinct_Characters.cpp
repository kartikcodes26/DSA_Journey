// Leetcode problem no 340. Longest Substring with K Distinct Characters
// problem statement: Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

class Solution {
  public:
    int longestKSubstr(string &s, int k) {

        unordered_map<char, int> mp;  // Create a hashmap
        int low = 0;
        int high = 0;
        int res = 0;
        // k a r t i k

        for(high = 0; high < s.size(); high++)
        {
            mp[s[high]]++; // Add the element or increment it;
            // mp.size() returns the number of distict elemets in it
            while(mp.size() > k)
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                {
                    mp.erase(s[low]);
                }
                low++;
            }

            if(mp.size() == k)
            {
                res = max(res, high - low + 1); // Return the size of the window
            }
        }

        if(res == 0)
        {
            return -1;
        }
        else
        {
            return res;
        }

    }
};
