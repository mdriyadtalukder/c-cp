#include <bits/stdc++.h>
using namespace std;
//same as subset just ans er size k er soman hole ta result e dukabo..
void backtrack(vector<int> &v, vector<int> &ans, int i, vector<vector<int>> &myv, int k)
{

    if (i == v.size())
    {
        if (ans.size() == k)
        {
            myv.push_back({ans});
        }
        return;
    }
    ans.push_back(v[i]);
    backtrack(v, ans, i + 1, myv, k);
    ans.pop_back();
    backtrack(v, ans, i + 1, myv, k);
}
vector<vector<int>> combine(int n, int k)
{
    vector<int> v(n), ans;
    vector<vector<int>> myv;
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }

    backtrack(v, ans, 0, myv, k);
    return myv;
}
