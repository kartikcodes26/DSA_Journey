// geeksforgeeks 1. Reverse a string using stack
// description: Given a string, the task is to reverse the string using stack data structure.
// time complexity: O(n)
// space complexity: O(n)
// Difficulty : Easy

class Solution {
  public:
    string reverse(const string& S) {
        // code here
        stack<char> st;

        for(int i = 0; i < S.size(); i++)
        {
            st.push(S[i]);
        }

        string result;
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
