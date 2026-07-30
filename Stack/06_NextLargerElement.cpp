// gfg problem: Next Greater Element
// Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element. If there does not exist next greater of current element, then next greater element for current element is -1.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
public:
    vector<int> nextLargerElement(vector<int>& nums) {
        stack<int> st;
        vector<int> res(nums.size());

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
