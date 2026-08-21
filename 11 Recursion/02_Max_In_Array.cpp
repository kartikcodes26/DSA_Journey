#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max_arr(const vector<int> &v,int n)
{
    // base case
    if(n == 0)
    {
        return v[0];
    }
    // Khud ka contribution + Samne wale ka contribution
    return max(v[n], max_arr(v, n - 1));
}

int main()
{
    vector<int> v {1, 99, 3, 4, 11};
    cout << max_arr(v, v.size() - 1);
}
