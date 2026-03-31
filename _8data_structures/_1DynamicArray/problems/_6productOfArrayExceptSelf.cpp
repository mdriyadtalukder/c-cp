
// sob gun hbe except current ar[i]...
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    int n = nums.size();

    vector<int> ans(n, 1);

    // prefix (store directly in ans)
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;

    // suffix
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1]; // ith suffix
        ans[i] *= suffix;
    }

    // print result
    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     vector<int> nums = {1, 2, 3, 4};
//     int n = nums.size();

//     vector<int> prefix(n, 1), suffix(n, 1), ans(n);

//     // prefix array
//     for (int i = 1; i < n; i++)
//     {
//         prefix[i] = prefix[i - 1] * nums[i - 1];
//     }

//     // suffix array
//     for (int i = n - 2; i >= 0; i--)
//     {
//         suffix[i] = suffix[i + 1] * nums[i + 1];
//     }

//     // result
//     for (int i = 0; i < n; i++)
//     {
//         ans[i] = prefix[i] * suffix[i];
//     }

//     // print result
//     for (int x : ans)
//     {
//         cout << x << " ";
//     }

//     return 0;
// }