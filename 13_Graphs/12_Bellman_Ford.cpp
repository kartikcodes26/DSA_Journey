// GFG problem name : Bellman Ford Algorithm
// difficulty : Medium
// link : https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// pattern : Bellman Ford Algorithm
// TC: O(V * E)
// SC: O(V)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> res(V, 1e8);
        res[src] = 0;

        // V - 1 baar relax karne se correct anser mil jana chaiye if no negative weights are present
        for(int i = 0; i < V - 1; i++)
        {
            for(int j = 0; j < edges.size(); j++)
            {
                int s = edges[j][0];
                int d = edges[j][1];
                int w = edges[j][2];

                if(res[s] != 1e8 && res[d] > res[s] + w)
                {
                    // relax kardo, feasible condition mil gyi hai
                    res[d] = res[s] + w;
                }
            }
        }

        // Ek aur baar relax karo to detect negative weights
        for(int j = 0; j < edges.size(); j++)
        {
            int s = edges[j][0];
            int d = edges[j][1];
            int w = edges[j][2];

            if(res[s] != 1e8 && res[d] > res[s] + w)
            {
                // Agar better answer mila toh matlab negative weights hai
                return {-1};
            }
        }

        return res;

    }
};
