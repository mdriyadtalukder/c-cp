#include <bits/stdc++.h>
using namespace std;
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