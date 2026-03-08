#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int> &arr, int idx, int tar,
                        vector<vector<int>> &ans, vector<int> &combin)
{
    if (idx == arr.size() || tar < 0)
        return;

    if (tar == 0)
    {
        if (s.find(combin) == s.end())
        {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);

    // single
    getAllCombinations(arr, idx + 1, tar - arr[idx], ans, combin);

    // multiple
    getAllCombinations(arr, idx, tar - arr[idx], ans, combin);

    combin.pop_back(); // backtracking

    // exclusion
    getAllCombinations(arr, idx + 1, tar, ans, combin);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> combin;

    getAllCombinations(arr, 0, target, ans, combin);

    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> res = combinationSum(arr, target);

    for (auto v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }
}