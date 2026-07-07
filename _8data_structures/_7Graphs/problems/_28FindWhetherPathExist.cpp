/*
1- Source
2-dest
3-Blank
0-Wall
2d matrix hbe with 0,1,2,3 value..1 theke 2 te jete hbe with shortest path.
.3 mane sudu ei poth diye jete parbo..0 mane block..wall ..eikhn diye jaoya jbe na..left,right,up,down e move krte parbo.
*/
// without visited array speace
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
    int a, b; // dont need
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
            else if (grid[i][j] == 2) // dont need
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

/*
Find Whether Path Exists

Problem Statement:

You are given an N × N grid.

Each cell contains one of the following values:

1 -> Source

2 -> Destination

3 -> Blank cell (can move)

0 -> Wall (blocked)

Determine whether there exists a path
from Source to Destination.

You may move only in four directions:

- Up
- Down
- Left
- Right

Return true if a path exists,
otherwise return false.

------------------------------------------------

Example 1:

Input:

grid =

{
    {3,0,3,0,0},
    {3,0,0,0,3},
    {3,3,3,3,3},
    {0,2,3,0,0},
    {3,0,0,1,3}
}

Output:

true

Explanation:

A valid path exists from Source (1)
to Destination (2) through cells
having value 3.

------------------------------------------------

Example 2:

Input:

grid =

{
    {1,0,0},
    {0,0,0},
    {0,2,3}
}

Output:

false

Explanation:

The destination cannot be reached.

------------------------------------------------

Constraints:

1 <= N <= 500

Grid values are only:

0, 1, 2, 3

There is exactly one Source
and exactly one Destination.

Expected Time Complexity:
O(N²)

Expected Auxiliary Space:
O(N²) in the worst case (queue)

Approach:

1. Find the Source (1) and Destination (2).
2. Start BFS from the Source.
3. Move only through cells having value
   1 or 3.
4. Mark visited cells by changing them to 0
   (no separate visited array required).
5. If Destination (2) is reached,
   return true.
6. Otherwise return false.
*/