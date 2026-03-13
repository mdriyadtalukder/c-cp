#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int k = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[k++] = nums[i];
        }
    }

    return k;
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

    int k = removeDuplicates(nums);

    cout << k << endl;

    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}