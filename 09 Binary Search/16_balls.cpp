// Leetcode 1552. Magnetic Force Between Two Balls
// link : https://leetcode.com/problems/magnetic-force-between-two-balls/
// TC : O(n log m) where n is the size of the array and m is the maximum distance between two balls
// SC : O(1) since we are using constant space for the pointers
// Difficulty : Medium
// Pattern : Binary Search

class Solution {
public:
    bool ispossible(vector<int>& position, int m, int mindist)
    {
        int previndex = position[0];
        int placed = 1;
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - previndex >= mindist)
            {
                previndex = position[i];
                placed++;
            }
        }
        return placed >= m;

    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int res = -1;
        bool found = false;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(ispossible(position, m, mid))
            {
                found = true;
                res = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(found) return res;
        else return -1;
    }
};
