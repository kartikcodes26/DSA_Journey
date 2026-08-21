#include <iostream>
using namespace std;

void printTill1(int i, int n)
{
    // Base Case
    if(i < 1)
    {
        return ;
    }
    cout << i << '\n';
    printTill1(i - 1, n);
}

int main()
{
    printTill1(4, 4);
}
