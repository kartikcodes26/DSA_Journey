#include <iostream>
#include <vector>
using namespace std;

int maxA(vector<int> heights)
{
    int i = 0;
    int j = heights.size() - 1;
    int res = 0;
    int area = 0;
    while(i <= j)
    {
        if(heights[i] <= heights[j])
        {
            area = heights[i] * (j - i);
            i++;
        }
        else
        {
            area = heights[j] * (j - i);
            j--;
        }
        res = max(area, res);
    }

    return res;
}

int main()
{
    vector<int> v1 {5, 1, 9, 1, 0, 2};
    cout << maxA(v1);
}