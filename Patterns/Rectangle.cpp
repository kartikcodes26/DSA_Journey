#include <iostream>
using namespace std;

void rectangle(int rows)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << "* ";
        }
        cout << '\n';
    }
}

int main()
{
    rectangle(10);
    return 0;
}