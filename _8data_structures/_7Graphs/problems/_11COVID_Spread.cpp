// 2d d array thkbe..jar jar value 2 taile oita covid patient.jar covid j tar upor,nich,dan,bam er cell re covid dibe mane 2 hbe
// koto unit time lgbe..like 2d te 4ta 2 ase tahole 4 ta 2 tar ashepashe covid dibe 1 unit e.
//.then latest patient tader ashe pashe covid dibe 1 unit e...1+1=2..so on

#include <bits/stdc++.h>
using namespace std;
// Direction arrays for moving in 4 directions
int row[4] = {-1, 1, 0, 0}; // Up, Down
int col[4] = {0, 0, -1, 1}; // Left, Right

int r;
int c;

// Check whether a cell is inside the grid
bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

int helpaterp(vector<vector<int>> hospital)
{
    // Number of rows and columns
    r = hospital.size();
    c = hospital[0].size();

    // Queue stores all currently infected patients
    queue<pair<int, int>> q;

    // Initially push every infected patient into the queue.
    // These all start spreading infection at time = 0.
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (hospital[i][j] == 2)
                q.push({i, j});

    // Total time required
    int timer = 0;

    // BFS starts
    while (!q.empty())
    {
        // Number of infected patients at the current minute
        int curr_patient = q.size();

        // Process only the current level
        while (curr_patient--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Visit all 4 neighbouring cells
            for (int k = 0; k < 4; k++)
            {
                int ni = i + row[k];
                int nj = j + col[k];

                // If neighbour is inside the grid
                // and is healthy, infect it
                if (valid(ni, nj) && hospital[ni][nj] == 1)
                {
                    hospital[ni][nj] = 2; // Mark as infected
                    q.push({ni, nj});     // It will infect others next minute
                }
            }
        }

        // If new infected patients exist,
        // another minute has passed.
        if (!q.empty())
            timer++;
    }

    // After BFS, if any healthy patient remains,
    // it means infection couldn't reach everyone.
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (hospital[i][j] == 1)
                return -1;

    // Otherwise return the total time taken
    return timer;
}
/* leetcode
994. Rotting Oranges
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.

*/