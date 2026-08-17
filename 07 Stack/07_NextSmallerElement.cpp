// gfg problem: Next Smaller Element
// Given an array arr[ ] of size N having distinct elements, the task is to find the next smaller element for each element of the array in order of their appearance in the array. Next smaller element of an element in the array is the nearest element on the right which is smaller than the current element. If there does not exist next smaller of current element, then next smaller element for current element is -1.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res(arr.size());

        for(int i = arr.size() - 1; i >=0; i--)
        {
            while(!st.empty() && st.top() >= arr[i])
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
            st.push(arr[i]);
        }

        return res;
    }
};
