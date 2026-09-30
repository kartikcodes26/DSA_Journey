// Leetcode problem: 200. Number of Islands
// Link : https://leetcode.com/problems/number-of-islands/
// Time Complexity : O(n * m)
// SC : O(n * m)
// Difficulty : Medium
// pattern : Graphs


class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>> &vis, int n, int m)
    {
        vis[i][j] = true;
        for(int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];
            if(valid(row, col, n, m) && grid[row][col] == '1' && !vis[row][col])
            {
                dfs(grid, row, col, vis, n, m);
            }
        }
        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false)); // 2D vector of bool false

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    dfs(grid, i, j, vis, n, m);
                    res++;
                }
            }
        }

        return res;
    }
};
