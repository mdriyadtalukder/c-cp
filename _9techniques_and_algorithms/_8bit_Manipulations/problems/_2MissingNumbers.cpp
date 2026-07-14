#include <bits/stdc++.h>
using namespace std;
// 0 theke n er xor then all element er xor like 0^3^1^0^1^2^3=2
int missingNumber(vector<int> &nums)
{
    int x = 0;
    int n = nums.size();

    // XOR all numbers from 0 to n
    for (int i = 0; i <= n; i++)
    {
        x ^= i;
    }

    // XOR all elements in array
    for (auto &i : nums)
    {
        x ^= i;
    }

    return x;
}

int main()
{
    int n;
    cin >> n; // size of array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << missingNumber(nums);

    return 0;
}