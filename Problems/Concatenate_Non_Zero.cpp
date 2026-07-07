#include <iostream>
using namespace std;

int con(int n)
{
    int temp = 0;
    int x = 0;
    int digit;
    int sum = 0;
    while(n != 0)
    {
        digit = n % 10;
        n = n / 10;
        if (digit != 0)
        {
            sum += digit;
            temp = (temp * 10) + digit;
        }
    }
    
    while(temp != 0)
    {
        digit = temp % 10;
        temp = temp / 10;
        if (digit != 0)
        {
            x = (x * 10) + digit;
        }
    }
    cout << x << '\n';
    return x * sum;
}

int main()
{
    cout << con(90067);
    return 0;
}