// 5 jon workers ase..ekek jon ekek din kaj kre..so 2 jon worker modde kon0 day mil ase..and max koto days mil ase 2 jon workers er modde of all them..
// 2ta binary num e set bit er mil ase j j index e oi index e tara 2jon e kaj kre..mil ase..0110 and 1100..so 2nd day te tarader 2 jon er e working day.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> masks(n, 0);

    for (int i = 0; i < n; ++i)
    {
        int num_workers;
        cin >> num_workers;

        int mask = 0;

        for (int j = 0; j < num_workers; ++j)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }

        masks[i] = mask;
    }

    int max_days = 0;
    int person1 = -1;
    int person2 = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {

            int intersection = (masks[i] & masks[j]); // ❌ missing &

            int common_days = __builtin_popcount(intersection); // ❌ fixed

            if (common_days > max_days)
            {
                max_days = common_days;
                person1 = i;
                person2 = j;
            }
        }
    }

    cout << person1 << " " << person2 << " " << max_days << endl;

    return 0;
}