#include <bits/stdc++.h>
using namespace std;
vector<int> findAnagrams(string s, string p)
{
    vector<int> v;
    if (s.size() < p.size())
        return v;

    vector<int> freqP(26, 0), freqS(26, 0);

    // build frequency for p
    for (char c : p)
    {
        freqP[c - 'a']++;
    }

    int k = p.size();

    // first window
    for (int i = 0; i < k; i++)
    {
        freqS[s[i] - 'a']++;
    }

    // check first window
    if (freqS == freqP)
        v.push_back(0);

    // sliding window
    for (int i = k; i < s.size(); i++)
    {
        // add new char
        freqS[s[i] - 'a']++;

        // remove old char
        freqS[s[i - k] - 'a']--;

        // compare
        if (freqS == freqP)
        {
            v.push_back(i - k + 1);
        }
    }

    return v;
}
int main()
{
    string s = "cbaebabacd", p = "abc";
    vector<int> l = findAnagrams(s, p);
    for (int h : l)
    {
        cout << h << " ";
    }
}