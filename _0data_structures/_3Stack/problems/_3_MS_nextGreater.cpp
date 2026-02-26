#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {6, 8, 0, 1, 3}, v(arr.size(), 0);
    stack<int> s;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i])
        {
            s.pop();
        }
        if (s.empty())
            v[i] = -1;
        else
            v[i] = s.top();
        s.push(arr[i]);
    }
    for (int val : v)
    {
        cout << val << " ";
    }
}