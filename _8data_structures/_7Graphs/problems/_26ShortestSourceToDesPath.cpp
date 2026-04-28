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