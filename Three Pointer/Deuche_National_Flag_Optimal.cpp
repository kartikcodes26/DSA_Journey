#include <iostream>
#include <vector>
using namespace std;

/*
000000,11111,012012012,22222222
0  low-1   mid         high
*/

/*

O(n) time
O(1) extra space

*/
void rearrange(vector<int> &arr)
{
    if(arr.empty()) return ;

    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while(mid <= high)
    {
        if(arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> v = {0,0,1,2,1,2,0,0,2,0,1};
    rearrange(v);

    for(auto ele : v)
    {
        cout << ele << " ";
    }
}
