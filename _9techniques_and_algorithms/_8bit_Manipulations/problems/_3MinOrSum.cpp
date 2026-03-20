#include <bits/stdc++.h>
using namespace std;
// array er 2 ta eement er shthe nijer iccha moto 2 ta element replace krbo jate a1|a2=r1|r2 hy..
// count krbo bunary te koita 1 ase..
void solve()
{
    int n;
    cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        x = y; // stores last element
    }

    cout << x << "\n";
}

int main()
{
    solve();
    return 0;
}