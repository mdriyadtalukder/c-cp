#include <bits/stdc++.h>
using namespace std;

//brute force
void reverses(vector<int> &a)
{
    reverse(a.begin(), a.end());
}
void rotate(vector<vector<int>> &matrix)
{
    vector<vector<int>> m(matrix.size(), vector<int>(matrix.size()));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            m[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < m.size(); i++)
    {
        reverses(m[i]);
    }

    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m.size(); j++)
        {
            matrix[i][j] = m[i][j];
        }
    }
}

//optimal
void rotateRow(vector<int> &ar)
{
    int i = 0, j = ar.size() - 1;

    while (i < j)
    {
        swap(ar[i], ar[j]);
        i++;
        j--;
    }
}

void rotate90(vector<vector<int>> &ar, int r, int c)
{

    // Transpose
    for (int i = 0; i < r; i++)
    {
        for (int j = i; j < c; j++)
        {
            swap(ar[i][j], ar[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < r; i++)
    {
        rotateRow(ar[i]);
    }
}

int main()
{
    vector<vector<int>> ar = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    rotate90(ar, 4, 4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}