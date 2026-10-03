// Leetcode Problem: 1971. Find if Path Exists in Graph
// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// Approach: BFS
// Difficulty: Medium

class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<vector<int>> adjL(V);
        for(int i = 0; i < edges.size(); i++)
        {
            adjL[edges[i][0]].push_back(edges[i][1]);
            adjL[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<int> res;
        vector<int> vis(V, 0);
        vis[src] = 1;

        while(!q.empty())
        {
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();

            if(node == dest)
            {
                return dist;
            }

            for(int j = 0; j < adjL[node].size(); j++)
            {
                int neigh = adjL[node][j];
                if(!vis[neigh])
                {
                    vis[neigh] = 1;
                    q.push({adjL[node][j], dist + 1});
                }
            }
        }

        return -1;
    }
};
