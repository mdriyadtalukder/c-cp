#include <bits/stdc++.h>
using namespace std;
// Brute force
//TC=O(ST)
int main()
{
    string s = "na";
    string t = "apna collegena";

    int S = s.size(), T = t.size();

    for (int i = 0; i <= T - S; i++)
    {
        if (t.substr(i, S) == s)
        {
            cout << "Found at index " << i << "\n";
        }
    }

    return 0;
}