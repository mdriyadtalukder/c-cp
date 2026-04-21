#include <bits/stdc++.h>
using namespace std;
int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;
    int maxLength = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += (nums[i] == 0 ? -1 : 1);
        if (map.count(sum))
        {
            maxLength = max(maxLength, i - map[sum]);
        }
        else
        {
            map[sum] = i;
        }
    }

    return maxLength;
}
int main() {}