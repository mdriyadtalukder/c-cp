#include <bits/stdc++.h>
using namespace std;
/*
#roated Array in 90 degree


it has 2 step

1.convert into transpose matrix
2.then rotate each row
*/
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