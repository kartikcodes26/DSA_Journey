// Leetcode 1221. Split a String in Balanced Strings
// Link : https://leetcode.com/problems/split-a-string-in-balanced-strings/
// Difficulty : Easy
// TC : O(n)
// SC : O(1)
// Approach : Greedy

class Solution {
public:
    int balancedStringSplit(string s) {
        vector<int> v{0, 0}; // R, L
        int res = 0;
        int low = 0;
        int high = 0;
        while(high < s.size())
        {
            if(s[high] == 'R') v[0]++;
            else v[1]++;
            if(v[0] == v[1])
            {
                res++;
                v[0] = 0;
                v[1] = 0;
                low = high;
            }
            high++;
        }

        return res;
    }
};
