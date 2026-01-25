#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 98364;
    vector<int> v;
    string s = to_string(a);
    for (char i : s)
    {
        // cout << i << " ";
        int l = i - '0';
        v.push_back(l);
    }
    for (int i : v)
    {
        cout << i << " ";
    }
}