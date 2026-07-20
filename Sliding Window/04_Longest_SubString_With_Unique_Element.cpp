// Leetcode 3. Longest Substring Without Repeating Characters
// Time Complexity: O(n)
// Space Complexity: O(n)
// Sliding Window Approach
// The idea is to use a hash map to store the characters and their counts in the current window.
// If the size of the hash map is less than the size of the window, it means there are duplicate characters in the window.
// We will shrink the window from the left until there are no duplicates in the window.

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        unordered_map<char,int> mp;
        int low = 0;
        int res = 0;

        for(int high = 0; high < s.size(); high++)
        {
            mp[s[high]]++;

            // Window ki size se mp ka size chota hai iska matlab duplicate characters present hai
            // agar equal hai to present nahi hai
            // Aur bada toh ho hii nahi sakta
            
            while(mp.size() < high - low + 1) // While duplicate characters are present
            {
                mp[s[low]]--;
                if(mp[s[low]] == 0)
                {
                    mp.erase(s[low]);
                }
                low++;
            }

            if(mp.size() == high - low + 1) // If no duplicates present
            {
                res = max(res, high - low + 1);
            }
        }

        return res;
    }
};
