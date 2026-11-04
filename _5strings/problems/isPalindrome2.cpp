#include <bits/stdc++.h>
using namespace std;
// brute force
bool isPalindrome(string t)
{
    int m = t.size();
    int left = 0;
    int right = m - 1;
    while (left < right)
    {
        if (t[left] != t[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool validPalindrome(string s)
{
    if (isPalindrome(s))
    {
        return true;
    }

    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        string candidate = s.substr(0, i) + s.substr(i + 1);
        if (isPalindrome(candidate))
        {
            return true;
        }
    }

    return false;
}

// optimal
bool validPalindrome2(string s)
{
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            // Mismatch: try skipping left or right character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }

    return true;
}

bool isPalindrome(const string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
        {
            return false;
        }
        left++;
        right--;
    }
    // No mismatch found, already a palindrome
    return true;
}