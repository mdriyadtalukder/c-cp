#include <bits/stdc++.h>
using namespace std;

// brute force(stack)
int minAddToMakeValid(string st)
{
    stack<char> s;

    for (int i = 0; i < st.size(); i++)
    {

        if (st[i] == '(')
        {
            s.push(st[i]);
        }
        else
        {
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(st[i]);
            }
        }
    }

    return s.size();
}

// optimal(greedy)
int minAddToMakeValid2(string s)
{
    int open = 0, close = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open++;
        else
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return open + close;
}

int main()
{

    string st = "(()(";
    cout << minAddToMakeValid(st) << endl;

    return 0;
}