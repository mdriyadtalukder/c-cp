#include <bits/stdc++.h>
using namespace std;

// dfs(brute force)

void dfs(vector<vector<int>> &grid, int row, int col,
         int baseRow, int baseCol, vector<pair<int, int>> &shape)
{
    if (row < 0 || row >= grid.size() ||
        col < 0 || col >= grid[0].size() ||
        grid[row][col] == 0)
    {
        return;
    }

    // Mark visited
    grid[row][col] = 0;

    // Store relative coordinates
    shape.push_back({row - baseRow, col - baseCol});

    // Explore four directions
    dfs(grid, row + 1, col, baseRow, baseCol, shape);
    dfs(grid, row - 1, col, baseRow, baseCol, shape);
    dfs(grid, row, col + 1, baseRow, baseCol, shape);
    dfs(grid, row, col - 1, baseRow, baseCol, shape);
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                vector<pair<int, int>> shape;

                dfs(grid, i, j, i, j, shape);

                st.insert(shape);
            }
        }
    }

    return st.size();
}

// dfs(optimal)
void dfs(vector<vector<int>> &grid, int row, int col,
         string &shape, char direction)
{
    if (row < 0 || row >= grid.size() ||
        col < 0 || col >= grid[0].size() ||
        grid[row][col] == 0)
    {
        return;
    }

    grid[row][col] = 0;

    // Store the direction
    shape += direction;

    dfs(grid, row + 1, col, shape, 'D');
    dfs(grid, row - 1, col, shape, 'U');
    dfs(grid, row, col + 1, shape, 'R');
    dfs(grid, row, col - 1, shape, 'L');

    // Backtracking
    shape += 'B';
}

int countDistinctIslands(vector<vector<int>> &grid)
{
    // unordered_set<string> st; (hash set) for optimal
    set<string> st;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                string shape;

                dfs(grid, i, j, shape, 'S');

                st.insert(shape);
            }
        }
    }

    return st.size();
}