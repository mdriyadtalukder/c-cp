
/*
Polynomial Rolling Hash Idea:

We treat a string like a number in base-p (here p = 31).

Mapping:
a = 1, b = 2, c = 3, ..., z = 26

Hash formula (your style):
hash = a[0] * p^0 + a[1] * p^1 + a[2] * p^2 + ...

Example:
string = "ab"
a = 1, b = 2

hash = (1 * 31^0) + (2 * 31^1)
     = 1 + 62
     = 63

So "ab" → 63

Important:
- Use modulo M to avoid overflow
- This helps in fast string comparison and finding duplicates
*/

#include <bits/stdc++.h>
using namespace std;
// counting distinct strings,
// tc=O(nm+logn)
const int N = 1e5 + 7;
const long long M = 1e9 + 7;

vector<long long> powers(N);
long long p = 31;

long long calculate_hash(string s)
{
    long long hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * powers[i]) % M;
    }
    return hash;
}

int main()
{

    // precompute powers
    powers[0] = 1;
    for (int i = 1; i < N; i++)
    {
        powers[i] = (powers[i - 1] * p) % M;
    }

    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "aa"};

    vector<long long> hashes;

    for (auto w : strings)
    {
        hashes.push_back(calculate_hash(w));
    }

    sort(hashes.begin(), hashes.end());

    int distinct = 0;

    for (int i = 0; i < hashes.size(); i++)
    {
        if (i == 0 || hashes[i] != hashes[i - 1])
        {
            distinct++;
        }
    }

    cout << distinct << endl;

    return 0;
}