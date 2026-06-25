#include <bits/stdc++.h>
using namespace std;
//without extra apace
int main()
{
    vector<vector<int>> ar = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int row = ar.size();
    int col = ar[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(ar[i][j], ar[j][i]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}