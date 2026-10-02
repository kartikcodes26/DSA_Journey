// Leetcode problem name : Is Graph Bipartite?
// Leetcode problem no : 785
// Link : https://leetcode.com/problems/is-graph-bipartite/
// Time Complexity : O(V + E)
// Space Complexity : O(V + E)
// Approach : DFS
// difficulty : Medium

class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int c, vector<int> &colors)
    {
        colors[node] = c;

        for(int i = 0; i < graph[node].size(); i++)
        {
            int neigh = graph[node][i];
            if(colors[neigh] != -1 && colors[neigh] == c)
            {
                return false;
            }
            else if(colors[neigh] == -1)
            {
                if(dfs(graph, neigh, 1 - c, colors) == false)
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++)
        {
            if(colors[i] == -1)
            {
                if(dfs(graph, i, 0, colors) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
