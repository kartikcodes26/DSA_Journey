#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rev(vector<int> &v, int l, int r)
{
    if(l >= r)
    {
        return ;
    }
    swap(v[l], v[r]);
    rev(v, l + 1, r - 1);
}
int main()
{
    vector<int> v1 {2, 3, 4, 5, 6, 7};
    rev(v1, 0, v1.size() - 1);
    for(auto ele : v1)
    {
        cout << ele << ' ';
    }
}
