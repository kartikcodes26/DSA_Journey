// Leetcode 1047. Remove All Adjacent Duplicates In String
// description: Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
// time complexity: O(n)
// space complexity: O(n)
// Difficulty : Easy

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string res;
        for(int i = 0; i < s.size(); i++)
        {
            if(!st.empty() && s[i] == st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
