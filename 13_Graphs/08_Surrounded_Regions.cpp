// Leetcode Problem: 130. Surrounded Regions
// Link: https://leetcode.com/problems/surrounded-regions/
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
// Approach: DFS
// Difficulty: Medium

class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int i, int j, int m, int n)
    {
        if(i >= m || i < 0 || j >= n || j < 0)
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        board[i][j] = '#';
        for(int k = 0; k < 4; k++)
        {
            int row = i + x[k];
            int col = j + y[k];
            if(valid(row, col, n, m) && board[row][col] == 'O')
            {
                dfs(board, row, col, n, m);
            }
        }
        return ;
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                {
                    dfs(board, i, j, board.size(), board[0].size());
                }
            }
        }

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O')
                {
                   board[i][j] = 'X';
                }
            }
        }

    }
};


