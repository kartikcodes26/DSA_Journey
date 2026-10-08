// gfg problem name : Minimum Spanning Tree
// Link: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Approach: Prim's Algorithm
// Difficulty: Medium
// Note: The graph is undirected and connected, so we can start from any node. Here, we start from node 0.

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adjL(V);
        for(int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            int w = edges[i][2];
            adjL[src].push_back({dest, w});
            adjL[dest].push_back({src, w});
        }

        int res = 0;
        vector<int> vis(V);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; // {wt, node}

        pq.push({0, 0});
        while(!pq.empty())
        {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            res = res + weight;
            vis[node] = 1;
            for(int j = 0; j < adjL[node].size(); j++)
            {
                int neigh = adjL[node][j].first;
                int w = adjL[node][j].second;
                if(!vis[neigh])
                {
                    pq.push({w, neigh});
                }
            }
        }

        return res;
    }
};
