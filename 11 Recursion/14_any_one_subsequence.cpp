#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &v)
{
    for(auto ele : v)
    {
        cout << ele << ' ';
    }
}

bool subsequence(vector<int> &v, int sum, int n, vector<int> &temp = {}, int cSum = 0, int i = 0)
{
    // Base-Case
    if(i >= n)
    {
        if(subsequence(v, sum, n, temp) == true)
        {
            if(sum == cSum)
            {
                printVec(temp);
                return true;
            }
            return false;
        }
    }


    temp.push_back(v[i]);
    cSum += v[i];
    if(subsequence(v, sum, n, temp, cSum, i) == true)
    {
        return true;
    }
    temp.pop_back(v[i]);
    cSum -= v[i];
    if(subsequence(v, sum, n, temp, cSum, i + 1) == true)
    {
        return true;
    }

    return false;
}
int main()
{
    vector<int> v = {1, 1, 2, 3, 4, 5};
    subsequence(v, 9, v.size());
}
