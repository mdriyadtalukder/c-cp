#include <bits/stdc++.h>
using namespace std;
// string of vector nibo and all ement er jnno letter count krbo..jid all letter which have in map%n==0 then true..coz sob words ek hbe..
bool canMakeEqual(vector<string> &v)
{
    unordered_map<char, int> m;
    for (auto str : v)
    {
        for (char c : str)
        {
            m[c]++;
        }
    }
    int n = v.size();
    /*
    for (auto ele : m)
{
    if (m[ele.first] % n != 0)
        return false;
}*/
    for (auto ele : m)
    {
        if (ele.second % n != 0)
            return false;
    }
    return true;
};
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << (canMakeEqual(v) ? "Yes" : "No") << endl;
    return 0;
}