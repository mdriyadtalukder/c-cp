#include <bits/stdc++.h>
using namespace std;
// Brute force
//TC=O(ST)
//LC 26
int main()
{
    string s = "na";
    string t = "apna collegena";

    int S = s.size();

    for (int i = 0; i <t.size(); i++)
    {
        if (t.substr(i, S) == s)
        {
            cout << "Found at index " << i << "\n"; //return i;
        }
    }

    return 0; //return -1;
}