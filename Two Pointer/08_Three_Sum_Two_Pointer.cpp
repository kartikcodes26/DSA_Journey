// Leetcode 15. 3Sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Lets suppose target = 0
// x + y + z = target
// v[i] + y + z = target
// y + z = target - v[i]

vector<vector<int>> threeSum(vector<int> arr, int result)
{
    if(arr.empty())
    {
        return {};
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    int target;
    int j;
    int k;


    for(int i = 0; i < arr.size() - 2; i++)
    {
        if(i > 0 && arr[i] == arr[i - 1]) continue; //first wala pair chalna chaiye

        j = i + 1;
        k = arr.size() - 1;

        target = result - arr[i];

        while(j < k)
        {
            if(arr[j] + arr[k] == target)
            {
                // Vector me triplet ka vector push kar do
                ans.push_back({arr[i], arr[j], arr[k]});

                // Aage badho jab tak same element hai
                while(j < k && arr[j] == arr[j + 1]) j++;
                while(j < k && arr[k] == arr[k - 1]) k--;

                // Next unique element pe baitho
                j++;
                k--;
            }
            else if(arr[j] + arr[k] < target)
            {
                j++;
            }
            else if(arr[j] + arr[k] > target)
            {
                k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(v1, 0);

    for(auto &triplet : result)
    {
        for(int x : triplet)
        {
            cout << x << " ";
        }
        cout << '\n';
    }

}

// Time Complexity : O(n^2)
// Space Complexity : O(1) if we don't consider the space used by the answer vector
