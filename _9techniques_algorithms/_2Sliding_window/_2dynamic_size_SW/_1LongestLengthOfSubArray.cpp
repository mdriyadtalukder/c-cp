#include <bits/stdc++.h>
using namespace std;
// 7 hoyte koto highest window er length
int main()
{
    int arr[] = {2, 1, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 7;
    int maxLength = 0;
    int sum = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum > target)
        {
            sum -= arr[j];
            j++;
        }

        if (i - j + 1 > maxLength)
        {
            maxLength = i - j + 1;
        }
    }

    cout << maxLength << endl;

    return 0;
}