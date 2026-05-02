// its string hashing based
// eita same 7 no ta..
//  ete TC hbe O(S+T)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const long long M = 1e9 + 7;
long long p = 31;

vector<long long> powers(N);

int32_t main()
{
    string s = "na";
    string t = "apnaacollegena";

    int T = t.size(), S = s.size();

    // precompute powers
    powers[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powers[i] = (powers[i - 1] * p) % M;
    }

    // prefix hash of text
    vector<long long> h(T + 1, 0);

    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % M;
    }

    // hash of pattern
    long long h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % M;
    }

    // search
    for (int i = 0; i + S <= T; i++)
    {
        long long cur_h = (h[i + S] - h[i] + M) % M;

        if (cur_h == (h_s * powers[i]) % M)
        {
            cout << "Found at index " << i << "\n";
        }
    }

    return 0;
}