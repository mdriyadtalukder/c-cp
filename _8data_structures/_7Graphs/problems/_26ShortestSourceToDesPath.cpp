// 2d matrix thkbe with 0,1 value..src thke des jete hbe shortest path be..
// src theke left,right,top,bottom e jete pari..but 0 er cell e jete parbona..sudu 1 er cell e jete parbo
// solve er jnno ekta matrix nibo with 0 value..j cell e visit krbo oitai 1 dibo..check krbo given matrix er cell 0 na and solve matrix er cell visited na..tailei jete parbo
// TC=SC=O(N×M)
// BFS
// without visited array speace

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        if (X == 0 && Y == 0)
            return 0;
        if (!A[0][0])
            return -1;
        
        // row, col, step
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}}); // (i, (j, step))

        A[0][0] = 0;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second.first;
            int step = q.front().second.second;
            q.pop();

            // up, down, left, right
            for (int k = 0; k < 4; k++)
            {
                int new_i = i + row[k];
                int new_j = j + col[k];

                if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                {
                    if (new_i == X && new_j == Y) // destination
                        return step + 1;

                    A[new_i][new_j] = 0;
                    q.push({new_i, {new_j, step + 1}});
                }
            }
        }
        return -1;
    }
};


/*
Shortest Source to Destination Path

Problem Statement:

You are given an N × M binary matrix.

Each cell contains either:

1 -> Walkable cell

0 -> Blocked cell

You start from the top-left corner (0,0).

Your destination is (X,Y).

You can move only in four directions:

- Up
- Down
- Left
- Right

Find the length of the shortest path
from (0,0) to (X,Y).

If the destination cannot be reached,
return -1.

------------------------------------------------

Example 1:

Input:

A =

{
    {1,1,1,1},
    {0,1,0,1},
    {1,1,1,1},
    {1,0,1,1}
}

Destination:

X = 3
Y = 3

Output:

6

Explanation:

One shortest path is:

(0,0)
↓

(0,1)
↓

(1,1)
↓

(2,1)
↓

(2,2)
↓

(2,3)
↓

(3,3)

Total moves = 6

------------------------------------------------

Example 2:

Input:

A =

{
    {1,0},
    {0,1}
}

Destination:

X = 1
Y = 1

Output:

-1

Explanation:

There is no valid path.

------------------------------------------------

Example 3:

Input:

A =

{
    {1}
}

Destination:

X = 0
Y = 0

Output:

0

Explanation:

Source and destination are the same.

------------------------------------------------

Constraints:

1 <= N, M <= 500

A[i][j] is either 0 or 1.

Expected Time Complexity:
O(N × M)

Expected Auxiliary Space:
O(N × M) in the worst case (queue)

Approach:

1. If the source is blocked, return -1.
2. Start BFS from (0,0).
3. Visit only valid cells having value 1.
4. Mark visited cells by changing them to 0
   (no separate visited array needed).
5. As soon as the destination is reached,
   return the current distance.
6. If BFS finishes without reaching the destination,
   return -1.
*/