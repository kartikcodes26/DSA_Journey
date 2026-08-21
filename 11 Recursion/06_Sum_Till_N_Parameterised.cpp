#include <iostream>
using namespace std;

void sumN(int i, int sum)
{
    if(i < 1)
    {
        cout << sum << '\n';
        return ;
    }
    sumN(i - 1, sum + i);
}

int main()
{
    sumN(10, 0);
}
