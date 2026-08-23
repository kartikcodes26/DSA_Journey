#include <iostream>
#include <vector>
using namespace std;

void printVec(vector<int> &v)
{
    for(auto ele : v)
    {
        cout << ele << ' ';
    }
    cout << '\n';
}

void sumK(vector<int> &v, int n, int k, int i = 0, vector<int> res = {}, int sum = 0)
{
    if(i >= n)
    {
        if(sum == k)
        {
            printVec(res);
        }
        return ;
    }
    res.push_back(v[i]);
    sum += v[i];
    sumK(v, n, k, i + 1, res, sum);
    res.pop_back();
    sum -= v[i];
    sumK(v, n, k, i + 1, res, sum);
}

int main()
{
    vector<int> v = {3, 1, 2};
    sumK(v, v.size(), 3);
}
