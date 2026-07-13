#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

Use two pointer apprach when :

1.	Array / Linked list
2.	Sorted
3.	Merge / remove duplicate / rearrange
4.	Detect Cycle
5.	Pair / triplet / Quadruplet
6.	No Extra Space

*/

/*
Question :

Given an array of integers and a target value, find two numbers whose sum equals the target. Return the pair of numbers.

Pattern: Two Pointers (after sorting)
*/

vector<vector<int>> twosum(vector<int> v, const int &target)
{
    if(v.empty())
    {
        return {};
    }
    
    sort(v.begin(), v.end());

    vector<vector<int>> sum;
    int i = 0;
    int j = v.size() - 1;


    while(i < j)
    {


        if(v[i] + v[j] == target)
        {
            sum.push_back({v[i], v[j]});

            // Tab tak khudao jab tak unique elemnt humara pointer na aa jaye
            // i < j because outer loop is not checked during this inner while loop
            while(i < j && v[i] == v[i+1]) i++;
            while(i < j && v[j] == v[j-1]) j--;

            i++;
            j--;
        }
        else if (v[i] + v[j] < target)
        {
            i++;
        }
        else if (v[i] + v[j] > target)
        {
            j--;
        }
    }
    return sum;
}

int main()
{
    vector<int> v1 = {};
    vector<vector<int>> result = twosum(v1, 0);
    for(auto &pair : result)
    {
        for(int x : pair)
        {
            cout << x << " ";
        }
        cout << '\n';
    }
}
