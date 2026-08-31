// Gfg problem name : Check if array is sorted
// gfg link : https://practice.geeksforgeeks.org/problems/check-if-array-is-sorted/0
// Difficulty: Easy
// TC : O(n)
// SC : O(n) (recursion stack space)
// Pattern : Recursion

class Solution {
  public:
    bool isSorted(vector<int>& arr, int i = 0) {
        // code here
        if(i == arr.size() - 1)
        {
            return true;
        }
        if(arr[i] > arr[i + 1])
        {
            return false;
        }

        return isSorted(arr, i + 1);
    }
};
