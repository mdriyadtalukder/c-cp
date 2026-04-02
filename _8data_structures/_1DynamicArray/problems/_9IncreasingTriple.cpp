#include <bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int> &nums)
{
    int first = INT_MAX;
    int second = INT_MAX;

    for (int num : nums)
    {
        if (num <= first)
        {
            first = num;
        }
        else if (num <= second)
        {
            second = num;
        }
        else
        {
            return true; // found third > second > first
        }
    }
    return false;
}

int main()
{

    vector<int> nums = {1, 2, 3, 4, 5};

    if (increasingTriplet(nums))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}