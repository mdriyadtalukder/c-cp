#include <bits/stdc++.h>
using namespace std;

// brute force
void reverseString(vector<char> &s)
{
    int n = s.size();
    vector<char> result;

    // Fill reversed array from back to front
    for (int i = n - 1; i >= 0; i--)
    {
        result.push_back(s[i]);
    }

    // Copy back into original array
    for (int i = 0; i < n; i++)
    {
        s[i] = result[i];
    }
}
// optimal
void reverseString(vector<char> &s)
{
    // reverse(s.begin(), s.end());

    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        // Swap characters at the two pointers
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}