#include <iostream>
using namespace std;

int main()
{
    const int n = 5;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << '\n';
    }
    return 0;
}