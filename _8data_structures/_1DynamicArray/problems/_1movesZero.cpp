#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j++;
        }
    }
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

    moveZeroes(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }

    return 0;
}