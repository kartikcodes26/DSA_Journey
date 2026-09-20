class Solution {
public:
    int ispossible(vector<int>& bloomDay, int m,int k, int day)
    {
        int bloomed = 0;
        int bouqets = 0;
        for(auto ele : bloomDay)
        {
            if(day >= ele)
            {
                bloomed++;
            }
            else
            {
                bloomed = 0;
            }
            if(bloomed >= k)
            {
                bouqets++;
                bloomed = 0;
            }

        }
        return bouqets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int low = 0;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res;
        bool found = false;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(ispossible(bloomDay, m, k, mid))
            {
                found = true;
                res = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if(found) return res;
        else return -1;
    }
};
