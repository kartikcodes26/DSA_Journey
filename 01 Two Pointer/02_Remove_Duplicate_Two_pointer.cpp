// Leetcode 26. Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.
// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
    // Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
    // Return k. 

#include <iostream>
#include <vector>
using namespace std;

// two pointer method
// Array is sorted
void remDup(vector<int> &v)
{
    if(v.empty()) return ;

    int i = 0;
    int n = v.size();

    for(int j = 1; j < n; j++)
    {
        if(v[i] != v[j])
        {
            // i is incremented first then used
            v[++i] = v[j];
        }
    }
    v.resize(i + 1);
}


int main() {
    // Vector must be sorted
    vector<int> v = {1,1,1,2,2,3,3,3};

    remDup(v);

    for(auto ele : v)
    {
        cout << ele << "  ";
    }

    return 0;
}
