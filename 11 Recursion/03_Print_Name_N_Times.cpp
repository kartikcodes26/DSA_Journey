#include <iostream>
using namespace std;

// Time complexity : O(N)
// Space complexity : O(N)
void printName(int i, int n)
{
    // Base Case
    if(i > n)
    {
        return ;
    }

    cout << i << " Foxy \n"; // Print name with counter

    printName(i + 1, n); // Call the func with increased i
}

int main()
{
    printName(1, 10);
}
