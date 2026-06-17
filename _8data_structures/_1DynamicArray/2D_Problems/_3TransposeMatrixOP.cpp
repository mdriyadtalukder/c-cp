#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> ar = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int n = ar.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        { // or j = i + 1
            swap(ar[i][j], ar[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}