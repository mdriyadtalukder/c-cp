#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        const char *cs = s.c_str();
        int a = cs[0] - '0';
        int b = cs[1] - '0';
        cout << a + b << endl;
    }
}
