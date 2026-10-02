// Gfg problem name : Topological Sort
// Link : https://practice.geeksforgeeks.org/problems/topological-sort/1
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)
// Approach : Kahn's Algorithm
// difficulty : Medium

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adjL(V);
        vector<int> res;
        vector<int> indeg(V);
        queue<int> q;

        for(int i = 0; i < edges.size(); i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            adjL[src].push_back(dest);
            indeg[dest]++;
        }

        for(int i = 0; i < indeg.size(); i++)
        {
            if(indeg[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int k = 0; k < adjL[node].size(); k++)
            {
                int neigh = adjL[node][k];
                indeg[neigh]--;

                if(indeg[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
        }

        return res;
    }
};
