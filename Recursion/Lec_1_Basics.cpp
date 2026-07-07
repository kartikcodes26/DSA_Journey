#include <iostream>
using namespace std;

int fun(int n)
{
    cout << "Going forward" << '\n';
    if(n == 0)
    {
        cout << "Going Backward \n";
        return 0;
    }
    return fun(n-1);
}

int main()
{
    fun(5);
    return 0;
}