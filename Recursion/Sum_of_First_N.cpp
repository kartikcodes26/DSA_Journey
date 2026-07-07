#include <iostream>
using namespace std;

void sum(int n, int res)
{
    if(n == 0)
    {
        cout << res;
        return ;
    }
    sum(n - 1, res + n);
}

int main()
{
    sum(5, 0);
    return 0;
}