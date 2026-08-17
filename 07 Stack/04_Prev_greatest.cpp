// Gfg problem: Previous Greater Element
// Given an array arr[ ] of size N having distinct elements, the task is to find the previous greater element for each element of the array in order of their appearance in the array. Previous greater element of an element in the array is the nearest element on the left which is greater than the current element. If there does not exist previous greater of current element, then previous greater element for current element is -1.
// Time Complexity: O(n)
// Space Complexity: O(n)
// Difficulty: Medium

class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        vector<int> res;
        stack<int> st;
        for(int i = 0; i < arr.size(); i++)
        {
            while(true)
            {
                if(st.empty())
                {
                    st.push(arr[i]);
                    res.push_back(-1);
                    break;
                }
                else if(st.top() <= arr[i])
                {
                    st.pop();
                }
                else if (st.top() > arr[i])
                {
                    res.push_back(st.top());
                    st.push(arr[i]);
                    break;
                }

            }
        }
        return res;
    }
};
