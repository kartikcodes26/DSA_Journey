#include <iostream>
using namespace std;

void triangle(int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
}

int main()
{
    triangle(10);
    return 0;
}