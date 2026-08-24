// Leetcode 455. Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies
// Time Complexity: O(nlogn + mlogm), where n is the length of the array g and m is the length of the array s.
// Space Complexity: O(1), as we are sorting the arrays in place.
// Description: Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie. Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
// Example 1:
// Input: g = [1,2,3], s = [1,1]
// Output: 1
// Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. And even though you have 2 cookies, since their size is both 1, you could only make the child with greed factor 1 content.
// Difficulty: Easy

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
