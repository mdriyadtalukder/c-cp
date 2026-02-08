#include <bits/stdc++.h>
using namespace std;
// int countSolutions=0;
bool isQueen(vector<string> &v, int row, int col, int n)
{
    for (int j = 0; j < n; j++) //-------------..horizontally
    {
        if (v[row][j] == 'Q')
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++) // ulta of row like '|'..vertically
    {
        if (v[i][col] == 'Q')
        {
            return false;
        }
    }

    // left diagonally ..row,col=current...row-1,col-1
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j] == 'Q')
        {
            return false;
        }
    }

    // right diagonally..row,col=current...row-1,col+1
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (v[i][j] == 'Q')
        {
            return false;
        }
    }

    return true;
}
void nQueens(vector<vector<string>> &res, int n, vector<string> &v, int k)

{
    // if (countSolutions >= 8) return; // stop recursion after 8 for geting exact 8 set
    if (k == n)
    {
        res.push_back({v});
        // countSolutions++;

        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isQueen(v, k, i, n))
        {
            v[k][i] = 'Q';
            nQueens(res, n, v, k + 1);
            v[k][i] = '.';
        }
    }
}
int main()
{
    int n = 8;
    vector<string> v(n, string(n, '.'));
    vector<vector<string>> res;
    nQueens(res, n, v, 0);

    cout << res.size() << " ";
}