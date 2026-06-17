#include <bits/stdc++.h>
using namespace std;
/*

every row er 1st or last element 1 hbe and r gula er upor er elem er jogfol hbe.1st raw te col hbe 1 ta then 2nd row te 2 ta so on.

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
int main()
{
    vector<vector<int>> ar(5);

    for (int i = 0; i < 5; i++)
    {
        ar[i] = vector<int>(i + 1); // like 1st row te 1 ta elem or column hbe.. then 2nd row te 2 then 3 then 4..so on

        ar[i][0] = ar[i][i] = 1; // 1st and last elem 1 hbe

        for (int j = 1; j < i; j++)
        {
            ar[i][j] = ar[i - 1][j] + ar[i - 1][j - 1]; // uporer 2 tar jogfol
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ar[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}