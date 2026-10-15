// Gfg problem: Minimum Platforms
// link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Difficulty: Medium
// Pattern: Intervals, two pointer
// Same as : Meeting rooms II

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int plats = 0;
        int res = 0;
        int i = 0;
        int j = 0;

        while(i < arr.size() && j < dep.size())
        {
            if(arr[i] <= dep[j])
            {
                // A train has arrived
               plats++;
               i++;
            }
            else if(arr[i] > dep[j])
            {
                // A train has departed
                plats--;
                j++;
            }
            res = max(res, plats);
        }

        return res;
    }
};
