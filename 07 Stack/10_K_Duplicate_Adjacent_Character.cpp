// Leetcode problem no: 1209. Remove All Adjacent Duplicates in String II
// Given a string s, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.
// We repeatedly make k duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        string res;

        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty() && st.top().first == s[i])
            {
                st.top().second++;
                if(st.top().second == k)
                {
                    st.pop();
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }

        while(!st.empty())
        {
            res.append((st.top()).second, (st.top()).first); // (count, character)
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
