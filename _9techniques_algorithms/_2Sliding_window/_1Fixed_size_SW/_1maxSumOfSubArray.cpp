#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {5, 1, 8, 2, 7, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;
    int sum = 0, ans = 0;

    // First window sum
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    ans = sum;

    int i = 0, j = k;

    // Sliding the window
    while (j < n)
    {
        sum += arr[j]; // Add next element
        sum -= arr[i]; // Remove previous element

        if (ans < sum)
        {
            ans = sum;
        }

        i++;
        j++;
    }

    cout << ans << endl;

    return 0;
}