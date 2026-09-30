// Leetcode problem: 994. Rotting Oranges
// Link : https://leetcode.com/problems/rotting-oranges/
// Time Complexity : O(n * m)
// SC : O(n * m)
// Difficulty : Medium
// pattern : Graphs

class Solution {
public:
    bool valid(int i, int j, int n, int m)
    {
        if(i < 0 || i >= n || j < 0 || j >= m)
        {
            return false;
        }
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh_count = 0;
        int time = 0;

        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                    grid[i][j] *= -1;
                }
                else if(grid[i][j] == 1)
                {
                    fresh_count++;
                }
            }
        }

        while(!q.empty() && fresh_count > 0)
        {
            time++;
            int s = q.size();
            while(s--)
            {
                pair<int, int> idx = q.front();
                q.pop();

                int r = idx.first;
                int c = idx.second;

                for(int k = 0; k < 4; k++)
                {
                    int row = r + x[k];
                    int col = c + y[k];

                    if(valid(row, col, n, m) && grid[row][col] == 1)
                    {
                        q.push({row, col});
                        grid[row][col] = -2;
                        fresh_count--;
                    }
                }
            }
        }

        if(fresh_count > 0)
        {
            return -1;
        }
        return time;
    }
};
