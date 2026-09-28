// gfg problem name : Breadth First Traversal for a Graph
// Link : https://practice.geeksforgeeks.org/problems/breadth-first-traversal
// Time Complexity : O(V + E)
// SC : O(V + E)
// Difficulty : Medium
// pattern : Graphs

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {

        int n = adj.size();
        vector<int> res;
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int node;

        while(!q.empty())
        {
            node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0; i < adj[node].size(); i++)
            {
                int neighbour = adj[node][i];
                if(vis[neighbour] == false)
                {
                    q.push(neighbour);
                    vis[neighbour] = true;
                }
            }
        }

        return res;
    }
};
