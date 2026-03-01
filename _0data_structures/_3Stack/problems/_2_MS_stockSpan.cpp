#include <bits/stdc++.h>
using namespace std;
// previous smaller range with current value
int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85}, ans(v.size(), 0);
    stack<int> s;
    for (int i = 0; i < v.size(); i++) // n
    {
        while (s.size() > 0 && v[s.top()] <= v[i]) // ekta element ekbar push hbe and pop hbe.. eita ekta limited time ondi cholbe..so n
        {
            s.pop();
        }
        if (s.empty())
            ans[i] = i + 1;
        else
            ans[i] = i - s.top();
        s.push(i);
    }
    for (int val : ans)
    {
        cout << val << " ";
    }
}
// overall TC=n+n=2n=O(n);