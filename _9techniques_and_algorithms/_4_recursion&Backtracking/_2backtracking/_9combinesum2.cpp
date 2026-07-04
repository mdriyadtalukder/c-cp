#include <bits/stdc++.h>
using namespace std;
//array theke 2 ta elem neoya jbe na for making target..ans set use korar drkr nai
vector<vector<int>> ans;
vector<int> path;

void solve(int idx, int target, vector<int> &candidates)
{

    if (target == 0)
    {
        ans.push_back(path);
        return;
    }

    if (idx >= candidates.size() || target < 0)
        return;

    // Take current element
    path.push_back(candidates[idx]);
    solve(idx + 1, target - candidates[idx], candidates);
    path.pop_back();

    // Skip all duplicates before the "not take" call
    while (idx + 1 < candidates.size() &&
           candidates[idx] == candidates[idx + 1])
    {
        idx++;
    }

    // Not take
    solve(idx + 1, target, candidates);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{

    sort(candidates.begin(), candidates.end());

    solve(0, target, candidates);

    return ans;
}
