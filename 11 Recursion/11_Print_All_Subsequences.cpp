#include <iostream>
#include <vector>
using namespace std;

/*
TC = 2^n * n
SC = O(n)
*/
void printVec(vector<int> &v)
{
    for(auto ele : v)
    {
        cout << ele << ' ';
    }
    cout << '\n';
}

void printSub(vector<int> &v, int i, int n, vector<int> res = {})
{
    if(i >= n)
    {
        printVec(res);
        return ;
    }
    res.push_back(v[i]); // Take
    printSub(v, i + 1, n, res); // Go ahead
    res.pop_back(); // Not Take
    printSub(v, i + 1, n, res); // Go ahead
}

int main()
{
    vector<int> v = {3, 1, 2};
    printSub(v, 0, v.size());
}
