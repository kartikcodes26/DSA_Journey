// Leetcode problem 1480. Running Sum of 1d Array
// link : https://leetcode.com/problems/running-sum-of-1d-array/
// Difficulty: Easy
// TC : O(n)
// SC : O(n)
// Pattern : Prefix Sum

class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        vector<int> ps(arr.size());
        ps[0] = arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            ps[i] = ps[i - 1] + arr[i];
        }

        return ps;
    }
};
