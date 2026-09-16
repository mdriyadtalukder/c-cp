#include <bits/stdc++.h>
using namespace std;

// Brute Force
int findContentChildrenBF(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    vector<bool> used(s.size(), false);
    int c = 0;
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (!used[j] && s[j] >= g[i])
            {
                c++;
                used[j] = true;
                break;
            }
        }
    }
    return c;
}

// Optimal(greedy)

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    while (i < g.size() && j < s.size())
    {
        if (s[j] >= g[i])
        {
            i++;
        }
        j++;
    }

    return i;
}

// Main Function
int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};

    cout << findContentChildren(g, s) << endl;

    return 0;
}