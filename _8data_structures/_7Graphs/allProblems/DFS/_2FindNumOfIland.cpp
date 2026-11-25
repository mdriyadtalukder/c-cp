
#include <bits/stdc++.h>
using namespace std;

// dfs

void dfs(vector<vector<char>> &grid, int row, int col)
{
    // Out of bounds or water -- stop
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0')
    {
        return;
    }
    // Sink the current cell to mark it visited
    grid[row][col] = '0';
    // Explore all four directions
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}
int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

// bfs

int r, c;
int row[4] = {-1, 0, 1, 0}, col[4] = {0, 1, 0, -1};
int numIslands(vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    r = grid.size();
    c = grid[0].size();
    int ct = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '1')
            {
                ct++;
                grid[i][j] = '0';
                q.push({i, j});
                while (!q.empty())
                {
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + row[k], nj = j + col[k];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '1')
                        {
                            grid[ni][nj] = '0';
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
    }
    return ct;
}
// int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
// int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
