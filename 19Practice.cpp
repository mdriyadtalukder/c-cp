#include <bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
        return s; // ✅ fix

    vector<string> v(numRows);
    bool b = true;
    int j = 0;
    string sl = "";

    for (int i = 0; i < s.size(); i++)
    {
        cout << j << endl;
        v[j].push_back(s[i]);
        if (j == 0)
        {
            b = true;
        }
        if (j == numRows - 1)
        {
            b = false;
        }

        if (b == true)
        {
            j++;
        }
        else
        {
            j--;
        }
    }

    for (auto l : v)
    {
        sl += l;
    }

    return sl;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 4;
    cout << convert(s, numRows);
}