#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    char ar[a][b];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> ar[i][j];
        }
    }
    int c = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (ar[i][j] == 'C' || ar[i][j] == 'M' || ar[i][j] == 'Y')
            {
                c++;
            }
        }
    }
    if (c == 0)
    {
        cout << "#Black&White" << endl;
    }
    else
    {
        cout << "#Color" << endl;
    }
}