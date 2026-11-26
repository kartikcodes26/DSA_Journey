// Gfg problem: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
// difficulty: Medium
// TC : O(nlogn) + O(n) = O(nlogn)
// SC : O(n)
// Approach: Greedy

class Solution {
  public:
    struct item {
        double val;
        double weight;
        double efficiency;
    };

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<item> items;
        int W = capacity;
        double res = 0;
        for(int i = 0; i < val.size(); i++)
        {
            items.push_back({
                (double)val[i],
                (double)wt[i],
                (double)val[i] / wt[i]
            });
        }

        // sorting by efficiency
        sort(items.begin(), items.end(),
            [](item a, item b) {
                return a.efficiency > b.efficiency;
        });

        for(auto item : items)
        {
            if(W == 0) break;
            if(item.weight <= W)
            {
                res += item.val;
                W -= item.weight;
            }
            else
            {
                res += ((item.val / item.weight) * W);
                break;
            }
        }
        return res;
    }
};
