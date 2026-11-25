#include <iostream>
using namespace std;
// brute force
bool backspaceCompare(string s, string t)
{
    string a, b;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '#')
            a.push_back(s[i]);
        else
        {
            if (!a.empty())
                a.pop_back();
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] != '#')
            b.push_back(t[i]);
        else
        {
            if (!b.empty())
                b.pop_back();
        }
    }
    return a == b;
}

// optimal

bool backspaceCompare(string s, string t)
{
    int i = s.length() - 1;
    int j = t.length() - 1;
    int skipS = 0;
    int skipT = 0;

    while (i >= 0 || j >= 0)
    {
        // Find the next valid character in s
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skipS++;
                i--;
            }
            else if (skipS > 0)
            {
                skipS--;
                i--;
            }
            else
            {
                break;
            }
        }

        // Find the next valid character in t
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skipT++;
                j--;
            }
            else if (skipT > 0)
            {
                skipT--;
                j--;
            }
            else
            {
                break;
            }
        }

        // Compare the two valid characters
        if (i >= 0 && j >= 0)
        {
            if (s[i] != t[j])
            {
                return false;
            }
        }
        else if (i >= 0 || j >= 0)
        {
            // One string has characters left, the other doesn't
            return false;
        }

        i--;
        j--;
    }

    return true;
}