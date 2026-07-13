#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int> &arr)
{
    int zeroes = 0;
    int ones = 0;

    for(size_t a = 0; a < arr.size(); a++)
    {
        if(arr[a] == 0) zeroes++;
        else if (arr[a] == 1) ones++;
    }

    for(size_t i = 0; i < zeroes; i++)
    {
        arr[i] = 0;
    }

    for(size_t j = zeroes; j < zeroes + ones; j++)
    {
        arr[j] = 1;
    }
    for(size_t z = zeroes + ones; z < arr.size(); z++)
    {
        arr[z] = 2;
    }
}
int main()
{
    vector<int> v1 {0, 1, 2, 2, 2, 0, 1, 0, 2};
    rearrange(v1);

    for(auto ele : v1)
    {
        cout << ele << " ";
    }
}
