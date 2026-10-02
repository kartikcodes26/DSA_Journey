// leetcode no : 207
// Link : https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time Complexity : O(V + E)
// SC : O(V + E)
// Difficulty : Medium
// pattern : Graphs


class Solution {
  public:
    bool dfscheck(vector<vector<int>> &edges, int node, vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for(int i = 0; i < edges[node].size(); i++)
        {
            int newnode = edges[node][i];
            if(!vis[newnode])
            {
                if(dfscheck(edges, newnode, vis, pathvis)) return true;
            }
            else if(pathvis[newnode])
            {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<vector<int>> adjL(V);

        for(auto ele : edges)
        {
            adjL[ele[0]].push_back(ele[1]);
        }

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
               if(dfscheck(adjL, i, vis, pathvis)) return true;
            }
        }
        return false;
    }
};
