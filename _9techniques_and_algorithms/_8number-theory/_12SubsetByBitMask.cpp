/*
Given days = [2, 4, 5]---2^n=2^3=8..so total 8 ta..0-7
0-7 er binary num ber krbo and set bt er position diye subset banabo
2=0th position,4=1st position,5=2nd position...

Mask representation:

0 -> 000 -> []
1 -> 001 -> [2]
2 -> 010 -> [4]
3 -> 011 -> [2, 4]
4 -> 100 -> [5]
5 -> 101 -> [2, 5]
6 -> 110 -> [4, 5]
7 -> 111 -> [2, 4, 5]
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    int subset_ct = (1 << n);

    vector<vector<int>> result;

    for (int mask = 0; mask < subset_ct; ++mask)
    {
        vector<int> subset;

        for (int i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }

        result.push_back(subset);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<int>> ans = subsets(nums);

    // print all subsets
    for (auto subset : ans)
    {
        cout << "[ ";
        for (auto x : subset)
        {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}