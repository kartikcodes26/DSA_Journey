// gfg problem: Previous Smaller Element
// Given an array arr[ ] of size N having distinct elements, the task is to find the previous smaller element for each element of the array in order of their appearance in the array. Previous smaller element of an element in the array is the nearest element on the left which is smaller than the current element. If there does not exist previous smaller of current element, then previous smaller element for current element is -1.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int> st;
        vector<int> res;

        for(int i = 0; i < arr.size(); i++)
        {
            while(!st.empty() && st.top() >= arr[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                res.push_back(-1);

            }
            else
            {
                res.push_back(st.top());
            }
            st.push(arr[i]);
        }

        return res;

    }
};
