#include <iostream>
using namespace std;

int sum(int n)
{
    //Base case
    if(n == 1)
    {
        return 1;
    }

    return n + sum(n - 1); // Apna contribution + Aage wale ka contribution
}

int main()
{
    cout << sum(10);
    /*
    Sum(5) = 5 + Sum(4)
                    4 + Sum(3)
                        3 + Sum(2)
                            2 + Sum(1)
                                1  (Base case reached)

    */
}
