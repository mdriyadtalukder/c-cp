#include <bits/stdc++.h>
using namespace std;
vector<string> res;
// bool isValid(string s)
// {
//     int count = 0;
//     for (char &i : s)
//     {
//         if (i == '(')
//             count++;
//         else
//             count--;
//         if (count < 0)
//             return false;
//     }
//     return count == 0;
// }
void genPan(string s, int n, int o, int c)
{
    if (s.length() == 2 * n)
    {
        // if (isValid(s))
        // {
        //     res.push_back(s);
        // }
        res.push_back(s);
        return;
    }
    if (o < n)
    {
        s.push_back('(');
        genPan(s, n, o + 1, c);
        s.pop_back();
    }

    if (c < o)
    {
        s.push_back(')');
        genPan(s, n, o, c + 1);
        s.pop_back();
    }
}
int main()
{
    int n = 3;
    int open = 0, close = 0;
    string s = "";
    genPan(s, n, open, close);

    for (string s : res)
    {
        cout << s << " ";
    }
}