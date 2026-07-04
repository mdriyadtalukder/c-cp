#include <bits/stdc++.h>
using namespace std;
// number 1-9 er modde use krte hbe and array er size k er soman hote hbe to make n;
vector<vector<int>> ans;
vector<int> path;

void solve(int num, int k, int target)
{

    // Found a valid combination
    if (target == 0 && path.size() == k)
    {
        ans.push_back(path);
        return;
    }

    // Base cases
    if (num > 9 || target < 0 || path.size() > k)
        return;

    // Take current number
    path.push_back(num);
    solve(num + 1, k, target - num);
    path.pop_back();

    // Don't take current number
    solve(num + 1, k, target);
}

vector<vector<int>> combinationSum3(int k, int n)
{

    solve(1, k, n);

    return ans;
}
