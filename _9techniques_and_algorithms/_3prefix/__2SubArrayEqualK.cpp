#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    int count = 0;

    for (int curr : nums)
    {
        sum += curr;
        int target = sum - k;
        if (map.count(target))
        {
            count += map[target];
        }
        map[sum]++;
    }

    return count;
}
int main() {}