#include <iostream>
using namespace std;

void num(int n)
{
    if(n == 0)
    {
        return ;
    }
    num(n-1);
    cout << n << '\n';
}

int main()
{
    num(10);
    return 0;
}