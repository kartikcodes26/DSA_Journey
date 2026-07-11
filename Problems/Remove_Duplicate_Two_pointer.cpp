#include <iostream>
#include <vector>
using namespace std;

// two pointer method
void remDup(vector<int> &v)
{
    if(v.empty()) return ;
    
    int i = 0;
    int n = v.size();
    
    for(int j = 1; j < n; j++)
    {
        if(v[i] != v[j])
        {
            // i is incremented first then used
            v[++i] = v[j];
        }
    }
    v.resize(i + 1);
}


int main() {
    // Vector must be sorted 
    vector<int> v = {1,1,1,2,2,3,3,3};
    
    remDup(v);
    
    for(auto ele : v)
    {
        cout << ele << "  ";
    }
    
    return 0;
}
