#include <iostream>
using namespace std;

void printTillN(int i, int n)
{
    // Base Case
    if(i > n)
    {
        return ;
    }
    cout << i << '\n';
    printTillN(i + 1, n);
}

int main()
{
    printTillN(1, 10);
}
