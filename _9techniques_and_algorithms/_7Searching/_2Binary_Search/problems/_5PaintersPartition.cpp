#include <bits/stdc++.h>
using namespace std;
//n board deoya ase ..each index er value hbe board er size..m painter deoya ase..m painter sob board k paint krte hbe..
//1 unit board paint krte 1 unit painter drkr..
// check if painting is possible within given time
// sob possible er max er modde min konta..

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++)
    {

        // if a single board takes more time than allowed
        if (arr[i] > maxAllowedTime)
            return false;

        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }

    return painters <= m;
}

// main logic
int minTimeToPaint(vector<int> &arr, int n, int m)
{
    int sum = 0, maxVal = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum;
    int ans = -1;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid))
        { // left
            ans = mid;
            end = mid - 1;
        }
        else
        { // right
            st = mid + 1;
        }
    }

    return ans;
}

// main function
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minTimeToPaint(arr, n, m);

    return 0;
}