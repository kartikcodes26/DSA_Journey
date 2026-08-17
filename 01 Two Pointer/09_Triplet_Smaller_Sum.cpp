// Leetcode 259. 3Sum Smaller

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Lets suppose target = 0
// x + y + z = target
// v[i] + y + z = target
// y + z = target - v[i]

// Goal : To return the number of pairs whose sum is less than the target
int threeSmallerSum(vector<int> arr, int result)
{
    if(arr.empty())
    {
        return {};
    }

    sort(arr.begin(), arr.end());



    int target;
    int counter = 0;
    int j;
    int k;


    for(int i = 0; i < arr.size() - 1 ; i++)
    {
        if(i > 0 && arr[i] >= arr[i - 1]) continue; //first wala pair chalna chaiye

        j = i + 1;
        k = arr.size() - 1;

        target = result - arr[i];

        while(j < k)
        {
            if(arr[j] + arr[k] >= target)
            {
                k--;
            }
            else if(arr[j] + arr[k] < target)
            {
                counter = counter + (k - j);
                j++;
            }
        }
    }
    return counter;
}

int main()
{
    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    cout << threeSmallerSum(v1, 3);

}
