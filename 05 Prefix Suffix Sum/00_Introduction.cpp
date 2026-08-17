#include <iostream>
#include <vector>
using namespace std;


int main()
{
    // Prefix sum
    vector<int> v {9,8,1,0,4,7,2};
    vector<int> prefix(7);
    prefix[0] = 0;
    // prefix[i] = prefix[i - 1] + v[i - 1]

    for(int i = 1; i < v.size(); i++)
    {
        prefix[i] = prefix[i - 1] + v[i - 1];
    }
    for(auto e : v)
    {
        cout << e << ' ';
    }
    cout << '\n';
    for(auto ele : prefix)
    {
        cout << ele << ' ';
    }
}
