// leetcode 1358. Number of Substrings Containing All Three Characters
// link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// TC : O(n) where n is the size of the array
// SC : O(1) since we are using extra space for the map
// difficulty : Medium
// pattern : Sliding Window

class Solution {
public:
    int atmostn(string s, int n)
    {
        int low = 0;
        int high = 0;
        int res = 0;
        unordered_map<char, int> mp;

        while(high < s.size())
        {
            mp[s[high]]++;

            while(mp.size() > n)
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                {
                    mp.erase(s[low]);
                }
                low++;
            }

            res += high - low + 1;

            high++;
        }

        return res;
    }
    int numberOfSubstrings(string s) {
        return atmostn(s, 3) - atmostn(s, 2);
    }
};
