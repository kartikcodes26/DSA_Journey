// Leetcode problem no: 503. Next Greater Element II
// Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> st;

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            st.push(nums[i]);
        }

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                res[i] = -1;
            }
            else
            {
                res[i] = st.top();
            }
            st.push(nums[i]);
        }

        return res;
    }
};
