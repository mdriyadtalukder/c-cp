#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        // No three positive numbers can sum to zero
        if (nums[i] > 0)
            break;

        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0)
            {
                left++;
            }
            else if (sum > 0)
            {
                right--;
            }
            else
            {
                result.push_back({nums[i], nums[left], nums[right]});
                // Skip duplicates for both pointers
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
        }
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

    vector<vector<int>> ans = threeSum(nums);

    for (auto &v : ans)
    {
        for (auto &x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}