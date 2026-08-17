// gfg problem link: https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// Problem Description: Given an array of n integers which represents the number of pages in n different books. You are given an integer k which represents the number of students. You are required to assign the books to the students such that the maximum number of pages assigned to a student is minimized. You need to return the minimum number of pages.
// Time Complexity: O(n log m) where n is the number of books and m is the sum of all pages in the books
// Space Complexity: O(1)
// Difficulty Level: Medium

class Solution {
  public:
    bool ispossible(vector<int> &arr,   long long k, long long guess)
    {


        long long students = 1;
        long long pages = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(pages + arr[i] > guess)
            {
                students++;
                pages = arr[i];
            }
            else
            {
                pages += arr[i];
            }
        }
        if(students > k)
        {
           return false;
        }
        else
        {
            return true;
        }
    }

    long long findPages(vector<int> &arr, long long k)
    {
        long long n = arr.size();
        if(k > n) return -1;

        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        long long res = -1;

        while(low <= high)
        {
            long long mid = (low + high) / 2;
            bool decision = ispossible(arr, k, mid);
            if(decision)
            {
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};
