#include <bits/stdc++.h>
using namespace std;
/* negative(included 0) and positive num ase array te..
jdi a[i]=a[i]+a[i+1] positive(0 theke boro) hy taholei ei i ta perform krbo..and for i,I can  do it for once.
find koto gula positive(0 bad e) num ase..
*/

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        // debug("STTTTTTT TT");

        int n;
        cin >> n;

        vector<long long> a(n);

        for (long long &i : a)
            cin >> i;

        long long sum = 0, ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            a[i] += sum;

            if (a[i] > 0)
                ans++;

            sum = max(a[i], 0LL);
        }

        cout << ans << endl;
    }

    return 0;
}