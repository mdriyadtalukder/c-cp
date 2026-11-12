#include <bits/stdc++.h>
using namespace std;

// Function to return sorted squares of a sorted array
// brute force
vector<int> sortedSquares(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = abs(nums[i] * nums[i]);
    }
    sort(nums.begin(), nums.end());
    return nums;
}
// optimal
vector<int> squares(const vector<int> &ar)
{
    int n = ar.size();
    vector<int> b(n);
    int i = 0, j = n - 1, k = n - 1;

    while (i <= j) // Use i <= j when every element must be processed, including the middle element.
    // Use i < j when you need to process pairs of elements.
    {
        if (abs(ar[i]) > abs(ar[j]))
        {
            b[k--] = ar[i] * ar[i];
            i++;
        }
        else
        {
            b[k--] = ar[j] * ar[j];
            j--;
        }
    }

    return b;
}

int main()
{
    vector<int> a = {-10, -5, -2, 1, 4, 9};
    vector<int> b = squares(a);

    for (int x : b)
    {
        cout << x << "\n";
    }

    return 0;
}