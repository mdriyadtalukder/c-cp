#include <bits/stdc++.h>
using namespace std;

// brute force
vector<vector<int>> generateMatrix(int n)
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> result(n, vector<int>(n, 0));

    // Direction vectors: right, down, left, up
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int dir = 0;
    int row = 0, col = 0, num = 1;

    for (int i = 0; i < n * n; i++)
    {
        result[row][col] = num++;
        visited[row][col] = true;

        int nextRow = row + dr[dir];
        int nextCol = col + dc[dir];

        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || visited[nextRow][nextCol])
        {
            dir = (dir + 1) % 4;
            nextRow = row + dr[dir];
            nextCol = col + dc[dir];
        }

        row = nextRow;
        col = nextCol;
    }

    return result;
}

//optimal
vector<vector<int>> generateMatrix2(int n)
{
    vector<vector<int>> ans(n, vector<int>(n, 0));

    int r = n;
    int c = n;

    int topRow = 0, bottomRow = r - 1;
    int leftCol = 0, rightCol = c - 1;

    int total = 0, num = 1;

    while (total < r * c)
    {

        // left → right
        for (int i = leftCol; i <= rightCol && total < r * c; i++)
        {
            ans[topRow][i] = num++;
            total++;
        }
        topRow++;

        // top | bottom
        for (int i = topRow; i <= bottomRow && total < r * c; i++)
        {
            ans[i][rightCol] = num++;
            ;
            total++;
        }
        rightCol--;

        // right <- left
        for (int i = rightCol; i >= leftCol && total < r * c; i--)
        {
            ans[bottomRow][i] = num++;
            ;
            total++;
        }
        bottomRow--;

        // bottom |^ top
        for (int i = bottomRow; i >= topRow && total < r * c; i--)
        {
            ans[i][leftCol] = num++;
            ;
            total++;
        }
        leftCol++;
    }

    return ans;
}