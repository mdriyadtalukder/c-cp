#include <bits/stdc++.h>
using namespace std;
//logn*n
// check if allocation is possible
//sob possible er max er modde min konta..
bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages)
{

    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++)
    {
        // single book has more pages than allowed
        if (arr[i] > maxAllowedPages)
            return false;

        if (pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else
        {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

// main function logic
int allocateBooks(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int st = 0, end = sum;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1; // try smaller answer
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

// main function
int main()
{
/*arr = [15, 17, 20],
N = 3
M = 2 */

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << allocateBooks(arr, n, m);

    return 0;
}