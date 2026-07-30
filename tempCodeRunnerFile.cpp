#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());
    vector<int> start;
    vector<int> end;

    for(int a = 0; a < points.size(); a++)
    {
        start.push_back(points[a][0]);
    }
    for(int a = 0; a < points.size(); a++)
    {
        end.push_back(points[a][1]);
    }
    int t = 0;
    int res = 0;
    int i = 0;
    int j = 0;
    while(i < start.size() && j < end.size())
    {
        if(start[i] < end[j])
        {
            i++;
        }
        else
        {
            j = i;
            res++;
        }
    }
    res++;
    return res;
}
int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}}; //Expected output: 2
    cout << findMinArrowShots(v);
}