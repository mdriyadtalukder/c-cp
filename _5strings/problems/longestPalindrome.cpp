#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    unordered_set<char> oddChars;
    int length = 0;
    for (char c : s)
    {
        if (oddChars.count(c))
        {
            // Pair completed, add 2 to length
            oddChars.erase(c);
            length += 2;
        }
        else
        {
            // First of a potential pair
            oddChars.insert(c);
        }
    }
    // If any unpaired characters remain, one can go in the center
    if (!oddChars.empty())
    {
        length++;
    }
    return length;
}