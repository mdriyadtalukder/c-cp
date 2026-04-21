#include <bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[0] = -1;
    long long sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        long long remainder = ((sum % k) + k) % k;
        if (map.count(remainder))
        {
            if (i - map[remainder] >= 2)
            {
                return true;
            }
        }
        else
        {
            map[remainder] = i;
        }
    }

    return false;
}