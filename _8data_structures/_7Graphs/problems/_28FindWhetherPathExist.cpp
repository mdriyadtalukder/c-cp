/*
1- Source
2-dest
3-Blank
0-Wall
2d matrix hbe with 0,1,2,3 value..1 theke 2 te jete hbe with shortest path.
.3 mane sudu ei poth diye jete parbo..0 mane block..wall ..eikhn diye jaoya jbe na..left,right,up,down e move krte parbo.
*/
//without visited array speace
#include <bits/stdc++.h>
using namespace std;
// Function to find whether a path exists from the source to destination.
int N;
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};
bool valid(int i, int j)
{
    return i >= 0 && i < N && j >= 0 && j < N;
}
bool is_Possible(vector<vector<int>> &grid)
{
    int x, y;
    int a, b;
    int n = grid.size();
    N = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                x = i;
                y = j;
            }
            else if (grid[i][j] == 2)
            {
                a = i;
                b = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k]) && grid[i + row[k]][j + col[k]])
                {
                    if (grid[i + row[k]][j + col[k]] == 2)
                        return true;

                    grid[i + row[k]][j + col[k]] = 0;
                    q.push({i + row[k], j + col[k]});
                }
            }
        }
    }
    return false;
}