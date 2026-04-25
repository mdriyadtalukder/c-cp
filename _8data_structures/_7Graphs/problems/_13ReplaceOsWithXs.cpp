// 2d array er jar value O  and O er upor ,nich,dan,bam e X thkle oita X hoye jbe..
// ba set of O nibo and same condition apply krbo then oi set of O gula X hbe.
// bfs
#include <bits/stdc++.h>
using namespace std;
int r;
int c;

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

bool valid(int i, int j)
{
    return i >= 0 && i < r && j >= 0 && j < c;
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)

{
    // int n = mat.size(), m = mat[0].size();
    r = n;
    c = m;

    queue<pair<int, int>> q;

    // first row
    for (int j = 0; j < c; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push(make_pair(0, j));
            mat[0][j] = 'T';
        }
    }

    // first column
    for (int i = 1; i < r; i++)
    {
        if (mat[i][0] == 'O')
        {
            q.push(make_pair(i, 0));
            mat[i][0] = 'T';
        }
    }

    // last row
    for (int j = 0; j < c; j++)
    {
        if (mat[r - 1][j] == 'O')
        {
            q.push(make_pair(r - 1, j));
            mat[r - 1][j] = 'T';
        }
    }

    // last column
    for (int i = 1; i < r; i++)
    {
        if (mat[i][c - 1] == 'O')
        {
            q.push(make_pair(i, c - 1));
            mat[i][c - 1] = 'T';
        }
    }

    // BFS
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
            {
                {
                    mat[i + row[k]][j + col[k]] = 'T';
                    q.push(make_pair(i + row[k], j + col[k]));
                }
            }
        }
    }

    // Replace all
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