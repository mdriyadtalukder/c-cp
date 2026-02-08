#include <bits/stdc++.h>
using namespace std;
void solve(int i, string &digit, string &temp, unordered_map<char, string> &mp, vector<string> &v)
{
    if (i >= digit.length())
    {
        v.push_back(temp);
        return;
    }
    char ch = digit[i];
    string s = mp[ch];
    for (int j = 0; j < s.length(); j++)
    {
        temp.push_back(s[j]);
        solve(i + 1, digit, temp, mp, v);
        temp.pop_back();
    }
}
int main()
{
    // if(digits.empty()) return{};
    string temp = "";
    vector<string> v;
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    int i = 0;
    string digits = "23";
    if (!digits.empty())
    {
        solve(i, digits, temp, mp, v);
        for (string s : v)
        {
            cout << s << " ";
        }
    }
    else
    {
        cout << "Empty";
    }
}