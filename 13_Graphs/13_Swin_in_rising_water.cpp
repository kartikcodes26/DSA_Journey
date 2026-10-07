// Leetcode problem: 778. Swim in Rising Water
// Link: https://leetcode.com/problems/swim-in-rising-water/
// Approach: Binary Search + BFS
// Time Complexity: O(n^2 * log(max_element)) where n is the size of the grid
// Space Complexity: O(n^2) for the visited array and queue
// difficulty: Hard

class Solution {
public:
    bool valid(int i, int j, int m, int n)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
        {
            return false;
        }
        return true;
    }
    bool bfs(vector<vector<int>>& grid, int m, int n, int guess)
    {
        if(m == 1 && n == 1) return true;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;
        int x[4] = {-1, 1, 0, 0};
        int y[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q; // {i, j};
        q.push({0, 0});

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++)
            {
                int r = row + x[k];
                int c = col + y[k];
                if(valid(r, c, m, n) && !vis[r][c] &&grid[r][c] <= guess)
                {
                    if(r == m - 1 && c == n - 1)
                    {
                        return true;
                    }
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int low = grid[0][0];
        int high = 0;
        int res = INT_MAX;

        // Max element of the matrix
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                high = max(high, grid[i][j]);
            }
        }

        // Binary search
        while(low <= high)
        {
            int guess = (low + high) / 2;
            if(bfs(grid, m, n, guess))
            {
                res = guess;
                high = guess - 1;
            }
            else
            {
                low = guess + 1;
            }
        }

        return res;
    }
};
