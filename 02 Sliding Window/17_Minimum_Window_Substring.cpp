// Leetcode Problem: 76. Minimum Window Substring
// link : https://leetcode.com/problems/minimum-window-substring/
// TC : O(n) where n is the size of the array
// SC : O(1) since we are using extra space for the map
// difficulty : Hard
// pattern : Sliding Window

class Solution {
public:
    bool isvalid(unordered_map<char, int> &mp1, unordered_map<char, int> &mp2)
    {
        for (auto &[key, value] : mp2)
        {
            if(mp2[key] > mp1[key])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int low = 0;
        int high = 0;
        int minlen = INT_MAX;
        int start = 0;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(auto ele : t)
        {
            mp2[ele]++;
        }
        while(high < s.size())
        {
            mp1[s[high]]++;

            while(isvalid(mp1, mp2))
            {
                if(high - low + 1 < minlen)
                {
                    start = low;
                    minlen = high - low + 1;
                }

                mp1[s[low]]--;
                if(mp1[s[low]] == 0)
                {
                    mp1.erase(s[low]);
                }
                low++;
            }

            high++;
        }
        if(minlen == INT_MAX) return "";
        return s.substr(start, minlen);

    }
};
