#include <iostream>
#include <vector>
using namespace std;

/*
note:
1. Both Arrays are sorted
2. Resultant array must be sorted too
3. Only positive integers
*/

// O(n + m) approach
vector<int> mergeSort(const vector<int> &v1, const vector<int> &v2)
{
    vector<int> result;
    result.reserve(v1.size() + v2.size());

    int i = 0;
    int j = 0;

    // Dono me se koi bhi end me nahi rehna chaiye
    while(i < v1.size() && j < v2.size())
    {
        if(v1[i] <= v2[j])
        {
            result.push_back(v1[i]);
            i++;
        }
        else if (v1[i] > v2[j])
        {
            result.push_back(v2[j]);
            j++;
        }

    }

    // Agar i ya j me se koi bhi end me naa pahuncha ho

    while (i < v1.size())
    {
        result.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        result.push_back(v2[j]);
        j++;
    }

    return result;

}

int main()
{
    vector<int> v1 = {1, 2, 4};
    vector<int> v2 = {3, 6, 9};

    vector<int> result = mergeSort(v1, v2);

    for(auto ele : result)
    {
        cout << ele << ' ';
    }
}
