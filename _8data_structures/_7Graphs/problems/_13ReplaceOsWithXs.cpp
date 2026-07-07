// 2d array er jar value O  and O er upor ,nich,dan,bam e X thkle oita X hoye jbe..
// ba set of O nibo and same condition apply krbo then oi set of O gula X hbe.
// bfs
#include <bits/stdc++.h>
using namespace std;

int r;
int c;

// 4 directions (Up, Down, Left, Right)
int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

// Check whether a cell is inside the grid
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    // Store dimensions
    r = n;
    c = m;

    // Queue for Multi-Source BFS
    queue<pair<int, int>> q;

    // -------------------------------------------------
    // Step 1:
    // Push every boundary 'O' into the queue
    // and mark it as temporary ('T').
    // These cells can never be converted into 'X'.
    // -------------------------------------------------

    // 1st and last col and row er O k chnage krbo na..tai T dara 1st e eder mark kre rakhbo
    //  First row
    for (int j = 0; j < c; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push({0, j});
            mat[0][j] = 'T';
        }
    }

    // Last row
    for (int j = 0; j < c; j++)
    {
        if (mat[r - 1][j] == 'O')
        {
            q.push({r - 1, j});
            mat[r - 1][j] = 'T';
        }
    }

    // First column
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] == 'O')
        {
            q.push({i, 0});
            mat[i][0] = 'T';
        }
    }

    // Last column
    for (int i = 1; i < r; i++)
    {
        if (mat[i][c - 1] == 'O')
        {
            q.push({i, c - 1});
            mat[i][c - 1] = 'T';
        }
    }

    // -------------------------------------------------
    // Step 2:
    // BFS from every boundary 'O'.
    // Mark all connected 'O's as 'T'.
    // -------------------------------------------------
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        // Visit all 4 neighbours
        for (int k = 0; k < 4; k++)
        {
            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj) && mat[ni][nj] == 'O')
            {
                mat[ni][nj] = 'T';
                q.push({ni, nj});
            }
        }
    }

    // -------------------------------------------------
    // Step 3:
    // Traverse the entire grid.
    //
    // Remaining 'O' -> Surrounded -> Convert to 'X'
    // Temporary 'T' -> Safe -> Convert back to 'O'
    // -------------------------------------------------
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == 'T')
                mat[i][j] = 'O';
        }
    }

    return mat;
}

/*
LeetCode 130. Surrounded Regions

Problem Statement:
You are given an m × n board containing characters:

- 'X'
- 'O'

Capture all regions that are completely surrounded by 'X'.

A region is captured by replacing all 'O's with 'X's if the region
is completely surrounded.

An 'O' should NOT be replaced if it is connected (directly or
indirectly) to an 'O' on the boundary of the board.

Two cells are connected only in the four directions:
- Up
- Down
- Left
- Right

Input:
- board: An m × n matrix containing only 'X' and 'O'.

Output:
- Return the modified board after capturing all surrounded regions.

Example 1:

Input:
board = {
    {'X','X','X','X'},
    {'X','O','O','X'},
    {'X','X','O','X'},
    {'X','O','X','X'}
}

Output:
{
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','X','X','X'},
    {'X','O','X','X'}
}

Explanation:
The three 'O's in the middle are completely surrounded,
so they become 'X'.

The bottom 'O' is connected to the boundary,
so it remains 'O'.

Example 2:

Input:
board = {
    {'O'}
}

Output:
{
    {'O'}
}

Constraints:
1 <= m, n <= 200
board[i][j] is either 'X' or 'O'

Expected Time Complexity:
O(m × n)

Expected Auxiliary Space:
O(m × n)

Approach:
1. Push every boundary 'O' into a queue.
2. Perform Multi-Source BFS.
3. Mark every boundary-connected 'O' as temporary ('T').
4. Traverse the board:
   - Remaining 'O' → convert to 'X'.
   - Temporary 'T' → convert back to 'O'.
5. Return the modified board.
*/