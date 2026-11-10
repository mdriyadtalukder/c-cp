#include <bits/stdc++.h>
using namespace std;
// brute force
int main()
{

    string s = "the sky is blue", l = "", r = "";
    vector<string> v;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (!l.empty())
            {
                v.push_back(l);
                l = "";
            }
            else
            {
                continue;
            }
        }
        else
        {
            l += s[i];
        }
    }
    if (!l.empty())
    {
        v.push_back(l);
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)

    {
        if (i == v.size() - 1)
        {
            r += v[i];
        }
        else
        {
            r += v[i] + " ";
        }
    }
    cout << r;
}

// optimal

string reverseWords(string s)
{
    reverse(s.begin(), s.end());

    int i = 0;
    int l = 0, r = 0;
    int n = s.length();

    while (i < n)
    {
        while (i < n && s[i] != ' ')
        {
            s[r] = s[i]; //  r ta i er value nicche
            // i barse so r o barse
            r++;
            i++;
        }

        if (l < r)
        {
            reverse(s.begin() + l, s.begin() + r); // reverse hocce l to r
            s[r] = ' ';                            // reverse er por next e space hocce
            r++;                                   // r bere next e gelo
        }

        l = r; // l and r same position e ashtese
        i++;   // i barbe always
    }

    // s = s.substr(0, r - 1); it makes sc o(n)
    s.resize(r - 1);

    return s;
}