// Leetcode 438. Find All Anagrams in a String
// Problem Statement: Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int low = 0;
        int high = p.size() - 1;

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        vector<int> res;
        for(int i = 0; i < p.size(); i++)
        {
            mp2[p[i]]++;
        }
        for(int i = 0; i < p.size(); i++)
        {
            mp1[s[i]]++;
        }
        while(high < s.size())
        {
            if(mp1 == mp2)
            {
                res.push_back(low);
            }
            mp1[s[low]]--;
            if(mp1[s[low]] == 0)
            {
                mp1.erase(s[low]);
            }
            low++;
            high++;
            mp1[s[high]]++;
        }
        return res;
    }
};
