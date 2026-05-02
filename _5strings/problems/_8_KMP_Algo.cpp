// Knuth-Morris-Pratt (KMP) String Matching Algorithm
//  7 no prblm er motoi..just count kre koi jaigai match krse s ta in t..
//  ete TC hbe O(S+T)
// KMP bes than rabin karp
#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }

        if (s[i] == s[j])
        {
            j++;
        }

        pi[i] = j;
    }

    return pi;
}

int main()
{
    string s = "na";
    string t = "apnacollege";

    vector<int> pi = prefix_function(s);

    int pos = -1;
    int i = 0, j = 0;

    while (i < t.size())
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }

        if (j == s.size())
        {
            pos = i - s.size();
            break;
        }
    }

    cout << pos << endl;

    return 0;
}

/* give index...same as 7
vector<int> indices;

while (i < t.size())
{
    if (t[i] == s[j])
    {
        i++;
        j++;
    }
    else
    {
        if (j != 0)
            j = pi[j - 1];
        else
            i++;
    }

    if (j == s.size())
    {
        indices.push_back(i - s.size()); // 👈 index stored
        j = pi[j - 1]; // continue searching
    }
}
*/