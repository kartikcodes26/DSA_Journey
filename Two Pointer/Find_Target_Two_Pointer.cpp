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

vector<int> twosum(vector<int> v, const int &target)
{
    sort(v.begin(), v.end());

    int i = 0;
    int j = v.size() - 1;
    

    while(i < j)
    {
        if(v[i] + v[j] == target)
        {
            return {v[i], v[j]};
        }
        else if(i == j)
        {
            return {};
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
}
int main()
{
    vector<int> v1 = {2,8,9,0,7};
    vector<int> result = twosum(v1, 10);
    cout << result[0] << " , " << result[1] << '\n';
}