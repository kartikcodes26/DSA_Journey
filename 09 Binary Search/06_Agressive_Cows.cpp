// gfg problem link: https://practice.geeksforgeeks.org/problems/aggressive-cows/1
// Problem Description: Given an array of n integers which represents the position of n stalls. You are given an integer k which represents the number of cows. You are required to assign the cows to the stalls such that the minimum distance between any two of them is as large as possible. You need to return the largest minimum distance.
// Time Complexity: O(n log m) where n is the number of stalls and m is the maximum distance between the first and last stall
// Space Complexity: O(1)
// Difficulty Level: Medium

class Solution {
  public:
    bool ispossible(vector<int> &arr, int k, int guess)
    {
        int cows = 1;
        int prevPos = arr[0];

        for(int i = 1; i < arr.size(); i++)
        {
            int space = arr[i] - prevPos;
            if(space < guess)
            {
                continue;
            }
            cows++;
            prevPos = arr[i];
        }
        if(cows >= k) return true;
        else return false;
    }

    int aggressiveCows(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 1;
        int high = arr[arr.size() - 1];
        int res;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            bool decision = ispossible(arr, k, mid);
            if(decision)
            {
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return res;
    }
};
