#include <bits/stdc++.h>
using namespace std;

// brute force
void setZeroes(vector<vector<int>> &m)
{

    vector<pair<int, int>> v;

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {
            if (m[i][j] == 0)
                v.push_back({i, j});
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < m[0].size(); j++)
        {

            m[v[i].first][j] = 0;
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {

            m[j][v[i].second] = 0;
        }
    }
}

// optimal
void setZeroes2(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    bool firstRowZero = false, firstColZero = false;

    // Check first row and column
    for (int j = 0; j < n; j++)
        if (matrix[0][j] == 0)
            firstRowZero = true;
    for (int i = 0; i < m; i++)
        if (matrix[i][0] == 0)
            firstColZero = true;

    // Use first row/col as markers..1st row and col zero kre dilam jar value 0 tar..
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeros based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }

    // Handle first row and column
    if (firstRowZero)
        for (int j = 0; j < n; j++)
            matrix[0][j] = 0;
    if (firstColZero)
        for (int i = 0; i < m; i++)
            matrix[i][0] = 0;
}
