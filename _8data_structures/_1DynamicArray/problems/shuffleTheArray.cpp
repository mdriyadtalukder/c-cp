#include <bits/stdc++.h>
using namespace std;

//brute force
vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> v;

    int i = 0, j = n, k = 0;

    while (j < nums.size())
    {
        k++;

        if (k % 2 != 0)
        {
            v.push_back(nums[i]);
            i++;
        }
        else
        {
            v.push_back(nums[j]);
            j++;
        }
    }

    return v;
}


//optimal
vector<int> shuffle2(vector<int> &nums, int n)
{
    int maxVal = 1001;

    // Encode: add shuffled value as the high part (base maxVal)
    for (int i = n - 1; i >= 0; i--)
    {
        // nums[n + i] goes to position 2*i+1
        nums[2 * i + 1] += (nums[n + i] % maxVal) * maxVal;
        // nums[i] goes to position 2*i
        nums[2 * i] += (nums[i] % maxVal) * maxVal;
    }

    // Decode: keep only the high part (the shuffled value)
    for (int i = 0; i < 2 * n; i++)
    {
        nums[i] = nums[i] / maxVal;
    }

    return nums;
}
int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    shuffle(nums, n);

    return 0;
}