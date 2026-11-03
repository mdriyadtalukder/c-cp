
#include <bits/stdc++.h>
using namespace std;
//brute force
// cell 0 hole and row col and diagonal total 8 ta er modde 3 ta 1 thkle oi cell 1 hoye jbe na hy 0 hbe..r cell ta 1 hole and and row col and diagonal total 8 ta er modde 2 ba 3 ta 1 hole cell ta 1 hbe na hy 0 hbe
int countLive(vector<vector<int>> &v, int row, int col, int n, int m)
{
    int live = 0;

    /* total 8 except current
    (i,j) = (-1,-1) (-1,0) (-1,1)
        (0,-1)   X     (0,1)
        (1,-1)  (1,0)  (1,1)

    */
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0) // curret cell
                continue;

            int nr = row + i;
            int nc = col + j;

            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                if (v[nr][nc] == 1)
                    live++;
            }
        }
    }

    return live;

    /*
     //if want 12 ---------------- extra 4 neighbors (distance 2)--but its invalid for life of code..just for know
    int extraX[] = {-2, 2, 0, 0};
    int extraY[] = {0, 0, -2, 2};

    for (int k = 0; k < 4; k++)
    {
        int nr = row + extraX[k];
        int nc = col + extraY[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m)
        {
            if (v[nr][nc] == 1)
                live++;
        }
    }

    return live;
    */
}

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> temp = board;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int live = countLive(temp, i, j, n, m);

            if (temp[i][j] == 1)
            {
                if (live == 2 || live == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
            else
            {
                if (live == 3)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
}
//optimal
void gameOfLife2(vector<vector<int>>& board) {
    int m = board.size();
    int n = board[0].size();
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dr[d];
                int nj = j + dc[d];
                // Bit 0 holds the original state
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && (board[ni][nj] & 1) == 1) {
                    liveNeighbors++;
                }
            }

            int currentState = board[i][j] & 1;
            // Determine next state and store in bit 1
            if (currentState == 1 && (liveNeighbors == 2 || liveNeighbors == 3)) {
                board[i][j] |= 2;
            } else if (currentState == 0 && liveNeighbors == 3) {
                board[i][j] |= 2;
            }
        }
    }

    // Right-shift to make next state the current state
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] >>= 1;
        }
    }
}