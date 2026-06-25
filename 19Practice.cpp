#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n; // size of arrays

        vector<int> a1(n), a2(n);

        // input array1
        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }

        // input array2
        for (int i = 0; i < n; i++)
        {
            cin >> a2[i];
        }

        vector<bool> used(n, false);

        // STEP 1: match a1 -> a2 (only increase allowed)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!used[j] && a2[j] >= a1[i])
                {
                    a1[i] = a2[j];
                    used[j] = true;
                    break;
                }
            }
        }

        // STEP 2: map values of a2 to index
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
        {
            pos[a2[i]] = i;
        }

        // convert a1 to index form
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = pos[a1[i]];
        }

        // STEP 3: count minimum swaps (cycle detection)
        vector<bool> vis(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] || arr[i] == i)
                continue;

            int cycle = 0;
            int j = i;

            while (!vis[j])
            {
                vis[j] = true;
                j = arr[j];
                cycle++;
            }

            swaps += (cycle - 1);
        }

        // output

        cout << swaps << endl;
    }

    return 0;
}