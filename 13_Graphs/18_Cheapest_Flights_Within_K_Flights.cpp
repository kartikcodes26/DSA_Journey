// Leetcode problem no 787. Cheapest Flights Within K Stops
// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// TC : O(k * E) where E is the number of edges in the graph
// SC : O(n) where n is the number of nodes in the graph
// difficulty : medium
// Pattern : Graphs, Bellman-Ford Algorithm

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n, 1e8);
        vector<int> tmp(n, 1e8);
        res[src] = 0;
        tmp[src] = 0;
        for(int i = 0; i < k + 1; i++)
        {
            for(int j = 0; j < flights.size(); j++)
            {
                int s = flights[j][0];
                int d = flights[j][1];
                int w = flights[j][2];

                if(res[s] != 1e8 && tmp[d] > res[s] + w)
                {
                    tmp[d] = res[s] + w;
                }
            }
            res = tmp;
        }


        return res[dst] != 1e8 ? res[dst]: -1;
    }
};
