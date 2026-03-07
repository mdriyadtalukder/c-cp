#include <bits/stdc++.h>
using namespace std;

void getPerms(string &s, int idx, vector<string> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = idx; i < s.size(); i++)
    {
        swap(s[idx], s[i]);      // choose
        getPerms(s, idx + 1, ans);
        swap(s[idx], s[i]);      // backtrack
    }
}

vector<string> permute(string s)
{
    vector<string> ans;
    getPerms(s, 0, ans);
    return ans;
}

int main()
{
    string s = "ABC";

    vector<string> result = permute(s);

    for (auto str : result)
    {
        cout << str << endl;
    }
}