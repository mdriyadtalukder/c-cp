#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();

    // Cyclic sort (index placement)
    for (int i = 0; i < n; i++)
    {
        while (nums[i] >0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // Find the first missing positive
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main()
{

    vector<int> nums = {1, 0, 2};

    int ans = firstMissingPositive(nums);
    cout << ans << endl;

    return 0;
}