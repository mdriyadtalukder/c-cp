// https://www.geeksforgeeks.org/problems/longest-possible-route-in-a-matrix-with-hurdles/1

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int dfs(int i, int j, int xd, int yd, vector<vector<int>> &mat)
    {

        if (i == xd && j == yd)
            return 0;

        int n = mat.size();
        int m = mat[0].size();

        mat[i][j] = 0; // mark visited

        int ans = -1;

        for (int k = 0; k < 4; k++)
        {

            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj, n, m) && mat[ni][nj])
            {

                int len = dfs(ni, nj, xd, yd, mat);

                if (len != -1)
                    ans = max(ans, len + 1);
            }
        }

        mat[i][j] = 1; // backtrack

        return ans;
    }

    int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd)
    {

        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;

        if (xs == xd && ys == yd)
            return 0;

        return dfs(xs, ys, xd, yd, mat);
    }
};

// class Solution
// {
// public:
//     int row[4] = {-1, 1, 0, 0};
//     int col[4] = {0, 0, -1, 1};

//     bool valid(int i, int j, int n, int m)
//     {
//         return i >= 0 && j >= 0 && i < n && j < m;
//     }

//     pair<int, int> countIslandsAndMaxSize(vector<vector<char>> &grid)
//     {

//         int n = grid.size();
//         int m = grid[0].size();

//         int islands = 0;
//         int maxSize = 0;

//         queue<pair<int, int>> q;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {

//                 if (grid[i][j] == 'L')
//                 {

//                     islands++;
//                     int size = 0;

//                     grid[i][j] = 'W';
//                     q.push({i, j});

//                     while (!q.empty())
//                     {

//                         int x = q.front().first;
//                         int y = q.front().second;
//                         q.pop();

//                         size++;

//                         for (int k = 0; k < 4; k++)
//                         {

//                             int nx = x + row[k];
//                             int ny = y + col[k];

//                             if (valid(nx, ny, n, m) && grid[nx][ny] == 'L')
//                             {

//                                 grid[nx][ny] = 'W';
//                                 q.push({nx, ny});
//                             }
//                         }
//                     }

//                     maxSize = max(maxSize, size);
//                 }
//             }
//         }

//         return {islands, maxSize};
//     }
// };