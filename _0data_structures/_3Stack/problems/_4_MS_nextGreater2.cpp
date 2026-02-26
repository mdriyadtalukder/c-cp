#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> num1 = {4, 1, 2}, num2 = {1, 3, 4, 2}, v;
    unordered_map<int, int> m;
    stack<int> s;
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= num2[i])
        {
            s.pop();
        }
        if (s.empty())
            m[num2[i]] = -1;
        else
            m[num2[i]] = s.top();
        s.push(num2[i]);
    }
    for (int i = 0; i < num1.size(); i++)
    {
        v.push_back(m[num1[i]]);
    }
    for (int val : v)
    {
        cout << val << " ";
    }
}