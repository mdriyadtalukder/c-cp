#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int sum = 0;
    int j = 0;
    int minN = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        while (sum >= target)
        {
            minN = min(minN, i - j + 1);
            sum -= nums[j];
            j++;
        }
    }

    return (minN == INT_MAX) ? 0 : minN;
}