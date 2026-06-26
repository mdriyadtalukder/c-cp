#include <bits/stdc++.h>
using namespace std;

/*
Row 0: P   A   H   N
Row 1: A P L S I I G   ← middle row
Row 2: Y   I   R

Visual path:

Row 0: P           I           N
Row 1: A       L  S       I   G
Row 2: Y   A      H   R
Row 3: P          I

1,2 te 2 jaigai kre ase
*/
string convert(string s, int numRows)
{
    if (numRows == 1)
        return s;

    string result = "";
    int jumps = (numRows - 1) * 2; // for last and first row

    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < s.size(); j += jumps)
        {
            result += s[j];

            // middle rows(jumps er ta + jumps-2*i er ta..coz eder 2 jaigai value thke)--i row no
            if (i > 0 && i < numRows - 1 && (j + jumps - 2 * i) < s.size())
            {
                result += s[j + jumps - 2 * i];
            }
        }
    }

    return result;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << convert(s, numRows) << endl;

    return 0;
}