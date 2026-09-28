// gfg problem name : Depth First Traversal for a Graph
// Link : https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Time Complexity : O(V + E)
// SC : O(V + E)
// Difficulty : Medium
// pattern : Graphs

class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int node, vector<int> &res, vector<bool> &vis)
    {
        res.push_back(node);
        vis[node] = true;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];
            if(vis[neighbour] == false)
            {
                DFS(adj, neighbour, res, vis);
            }
        }
        return ;
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> res;
        vector<bool> vis(adj.size(), 0);
        DFS(adj, 0, res, vis);

        return res;

    }
};
