#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    int count = 0;

    for (int curr : nums)
    {
        sum += curr;
        int remainder = ((sum % k) + k) % k;
        if (map.count(remainder))
        {
            count += map[remainder];
        }
        map[remainder]++;
    }

    return count;
}
int main() {}