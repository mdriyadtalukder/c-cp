// prefi sum ber krbo r map e dukabo ,,jdi dekhi ekta prefix sum already ase then oita r dukbo na..oi index obdi length calculate krbo 0 theke...like 5 index a equal hyse so 5-0(i-m[prefix]-->.age jekhne silo oitar length)..jid length ager result length er theke boro hy then calculate krbo..

#include <bits/stdc++.h>
using namespace std;
int maxLengthZeroSumSubarray(vector<int> &v)
{
    unordered_map<int, int> m;
    int prefixsum = 0;
    int maxlen = 0;
    for (int i = 0; i < v.size(); i++)
    {
        prefixsum += v[i];
        if (prefixsum == 0) // vector jid 0,0,0,0 hy tai emn..
        {
            maxlen++;
        }
        if (m.find(prefixsum) != m.end())
        {
            maxlen = max(maxlen, i - m[prefixsum]);
        }
        else
            m[prefixsum] = i;
    }
    return maxlen;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << maxLengthZeroSumSubarray(v) << endl;
    return 0;
}