// gfg problem name : Dijkstra's shortest path algorithm
// Link: https://practice.geeksforgeeks.org/problems/dijkstras-shortest-path-algorithm/0
// Time Complexity: O(E log V)
// Space Complexity: O(V + E)
// Approach: Dijkstra's Algorithm
// Difficulty: Medium


class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adjL(V); // Every pair {dest, weight}
        for(int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            int weight = edges[i][2];

            adjL[src].push_back({dest, weight});
            adjL[dest].push_back({src, weight});

        }

        vector<int> res(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // {weight, node}

        pq.push({0, src});
        res[src] = 0;
        while(!pq.empty())
        {
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(w > res[node]) continue;
            for(int k = 0; k < adjL[node].size(); k++)
            {
                int neigh = adjL[node][k].first;
                int neighW = adjL[node][k].second;
                if(res[neigh] > w + neighW)
                {
                    res[neigh] = w + neighW;
                    pq.push({w + neighW, neigh});
                }
            }
        }

        return res;
    }
};
