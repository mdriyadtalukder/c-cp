#include <bits/stdc++.h>
using namespace std;

// brute force
string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
        return s;

    vector<vector<char>> grid(numRows, vector<char>(s.size(), 0));
    int row = 0, col = 0;
    bool goingDown = true;

    for (int i = 0; i < s.size(); i++)
    {
        grid[row][col] = s[i];

        if (goingDown)
        {
            if (row == numRows - 1)
            {
                // Switch to diagonal up-right
                row--;
                col++;
                goingDown = false;
            }
            else
            {
                row++;
            }
        }
        else
        {
            if (row == 0)
            {
                // Switch back to going down
                row++;
                goingDown = true;
            }
            else
            {
                row--;
                col++;
            }
        }
    }

    string result;
    for (int r = 0; r < numRows; r++)
    {
        for (int c = 0; c < s.size(); c++)
        {
            if (grid[r][c] != 0)
            {
                result += grid[r][c];
            }
        }
    }
    return result;
}
//optimal

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