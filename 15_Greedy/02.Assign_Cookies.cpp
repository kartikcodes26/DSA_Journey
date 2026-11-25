// Leetcode problem no: 455
// Link : https://leetcode.com/problems/assign-cookies/
// difficulty : Easy
// Pattern : Greedy
// TC : O(nlogn + mlogm) where n is the number of children and m is the number of cookies
// SC : O(1) as we are not using any extra space

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // TC = nlogn + mlonm
        // SC = O(1)
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int res = 0;

        // Two pointer
        int i = 0;
        int j = 0;

        while(i < g.size() && j < s.size()) // Should not run out of bounds
        {
            if(g[i] <= s[j]) // Eligible child
            {
                // Give Cookie to child
                res++; // Update counter
                i++; // Child satisfied
                j++; // Cookie used
            }
            else
            {
                j++; // Cookie is wasted no one else will eat it as the arrays are sorted
            }
        }

        return res;
    }
};
