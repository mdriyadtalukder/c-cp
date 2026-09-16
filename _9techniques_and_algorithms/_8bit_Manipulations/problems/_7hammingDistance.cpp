#include <bits/stdc++.h>
using namespace std;
int hammingDistance(int x, int y)
{
    int xorVal = x ^ y;
    int count = 0;
    while (xorVal != 0)
    {
        xorVal = xorVal & (xorVal - 1);
        count++;
    }
    return count;
}

// string s, s2;

// void printBinary(int num, string &s)
// {
//     for (int i = 31; i >= 0; i--)
//     {
//         s.push_back(((num >> i) & 1));
//     }
// }

// int hammingDistance(int x, int y)
// {
//     s.clear();
//     s2.clear();

//     printBinary(x, s);
//     printBinary(y, s2);

//     int c = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         if (s[i] != s2[i])
//             c++;
//     }

//     return c;
// }
