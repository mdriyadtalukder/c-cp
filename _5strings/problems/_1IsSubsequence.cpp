#include <bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t)
{
    queue<char> st;
    for (auto a : s)
    {
        st.push(a);
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == st.front())
        {
            st.pop();
        }
    }
    return st.empty();
}
int main()
{
    string a = "abc", b = "ahbgdc";
    string s = isSubsequence(a, b) == true ? "true" : "false";
    cout << s;
}