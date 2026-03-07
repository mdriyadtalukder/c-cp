// circular array..so 2*length nibo like 1,2,3 so it will be 1,2,3,1,2,3..2*n.index will be 0 to 5..i%n use krbo..so 5%3=2 which is last index of main array
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {3, 6, 5, 4, 2}, v(arr.size(), 0);
    stack<int> s;
    for (int i = (arr.size() * 2) - 1; i >= 0; i--)
    {
        while (s.size() > 0 && s.top() <= arr[i % arr.size()])
        {
            s.pop();
        }
        if (s.empty())
            v[i % arr.size()] = -1;
        else
            v[i % arr.size()] = s.top();
        s.push(arr[i % arr.size()]);
    }
    for (int val : v)
    {
        cout << val << " ";
    }
}