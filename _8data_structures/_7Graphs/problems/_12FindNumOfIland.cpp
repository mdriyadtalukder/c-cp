// 2d matrix thkbe..value 0 mane pani and 1 mane iland..
// each 1 er upor,nich,dan,bam and diagonali te joto 1 ase mane iland ase sob mile ekta iland hbe..0 mane pani or break or bad..
// first 1 ke khujbo then ilend++ krbo and oitar row and column er index queue te dukabo and er ashepasher o diagonal sob zero banabo..

#include <bits/stdc++.h>
using namespace std;

int r;
int c;

// 8 possible directions
int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

// Check whether a cell is inside the grid
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int countIslands(vector<vector<char>> &grid)
{
    // Number of rows and columns
    r = grid.size();
    c = grid[0].size();

    // Queue for BFS
    queue<pair<int, int>> q;

    // Stores the number of islands
    int count = 0;

    // Traverse every cell of the grid
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // Found an unvisited land
            if (grid[i][j] == 'L') //1
            {
                // New island found
                count++;

                // Start BFS from this land cell
                q.push({i, j});

                // Mark it as visited by converting it to water
                grid[i][j] = 'W'; //0

                // BFS
                while (!q.empty())
                {
                    int new_i = q.front().first;
                    int new_j = q.front().second;
                    q.pop();

                    // Visit all 8 neighbours
                    for (int k = 0; k < 8; k++)
                    {
                        int ni = new_i + row[k];
                        int nj = new_j + col[k];

                        // If neighbour is inside the grid
                        // and is still land, visit it
                        if (valid(ni, nj) && grid[ni][nj] == 'L') //l
                        {
                            // Mark visited
                            grid[ni][nj] = 'W'; //0

                            // Add to queue
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }
    }

    // Return total islands
    return count;
}
/*
LeetCode / GFG Style Problem

Number of Islands (8-Directional)

Problem Statement:
You are given an m × n grid consisting of characters:

- 'L' represents Land.
- 'W' represents Water.

An island is a group of connected land cells ('L').

Two land cells are considered connected if they are adjacent
in any of the 8 directions:
- Up
- Down
- Left
- Right
- Top-Left
- Top-Right
- Bottom-Left
- Bottom-Right

Return the total number of islands in the grid.

Input:
- grid: An m × n character matrix containing
        only 'L' and 'W'.

Output:
- Return the number of islands.

Example 1:

Input:
grid = {
    {'L','L','W','W'},
    {'W','L','W','W'},
    {'W','W','L','W'},
    {'W','W','W','L'}
}

Output:
2

Explanation:
The first three land cells form one island because
they are connected.

The bottom-right land cell is diagonally connected to
the center land cell, so together they form the second island.

Example 2:

Input:
grid = {
    {'L','W','L'},
    {'W','W','W'},
    {'L','W','L'}
}

Output:
4

Explanation:
None of the land cells are connected,
so each land cell forms its own island.

Constraints:
1 <= m, n <= 500
grid[i][j] is either 'L' or 'W'

Expected Time Complexity:
O(m × n)

Expected Auxiliary Space:
O(m × n)

Approach:
1. Traverse every cell in the grid.
2. Whenever an unvisited land cell ('L') is found,
   increment the island count.
3. Perform BFS from that cell.
4. Visit all connected land cells in all 8 directions.
5. Mark visited cells as water ('W') so they are not processed again.
6. Continue until the entire grid has been traversed.
*/