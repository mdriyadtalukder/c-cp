#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {3, 1, 0, 8, 6}, ans(v.size(), 0);
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        while (s.size() > 0 && s.top() >= v[i])
        {
            s.pop();
        }
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(v[i]);
    }
    for (int val : ans)
    {
        cout << val << " ";
    }
}
