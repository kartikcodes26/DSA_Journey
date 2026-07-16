#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twosum(vector<int> &v, int target)
{
    unordered_map<int, int> mp;
    int need;
    for(int i = 0; i < v.size(); i++)
    {
        need = target - v[i];
        if(mp.find(need) != mp.end())
        {
            return {mp[need], i};
        }
        mp[v[i]] = i;
    }
    return {};
}

vector<int> twosumNum(vector<int> &v, int target)
{
    unordered_map<int, int> mp;
    int need;
    for(int i = 0; i < v.size(); i++)
    {
        need = target - v[i];
        if(mp.find(need) != mp.end())
        {
            return {need, v[i]};
        }
        mp[v[i]] = i;
    }
    return {};
}
// Returning numbers

int main()
{
    vector<int> v1 = {2,8,9,0,7};
    vector<int> result = twosum(v1, 10);
    cout << result[0] << " , " << result[1] << '\n';
    
    result = twosumNum(v1, 10);
    cout << result[0] << " , " << result[1];

}