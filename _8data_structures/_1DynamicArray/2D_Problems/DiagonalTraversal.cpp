#include <bits/stdc++.h>
using namespace std;
// brute force
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{

    int m = mat.size();
    int n = mat[0].size();

    map<int, vector<int>> mp;
    vector<int> result;

    // Fill the map using i + j
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i + j].push_back(mat[i][j]);
        }
    }

    bool flip = true;

    for (auto &it : mp)
    {

        if (flip)
        {
            reverse(it.second.begin(), it.second.end());
        }

        for (int &num : it.second)
        {
            result.push_back(num);
        }

        flip = !flip;
    }

    return result;
}
// optimal
vector<int> findDiagonalOrder2(vector<vector<int>> &mat)
{
    int m = mat.size(), n = mat[0].size();
    vector<int> result(m * n);
    int row = 0, col = 0;
    // direction: 1 = up-right, -1 = down-left
    int direction = 1;

    for (int i = 0; i < m * n; i++)
    {
        result[i] = mat[row][col];

        if (direction == 1)
        {
            // Moving up-right
            if (col == n - 1)
            {
                // Hit right edge, move down one row, switch direction
                row++;
                direction = -1;
            }
            else if (row == 0)
            {
                // Hit top edge, move right one column, switch direction
                col++;
                direction = -1;
            }
            else
            {
                // Normal up-right move
                row--;
                col++;
            }
        }
        else
        {
            // Moving down-left
            if (row == m - 1)
            {
                // Hit bottom edge, move right one column, switch direction
                col++;
                direction = 1;
            }
            else if (col == 0)
            {
                // Hit left edge, move down one row, switch direction
                row++;
                direction = 1;
            }
            else
            {
                // Normal down-left move
                row++;
                col--;
            }
        }
    }

    return result;
}