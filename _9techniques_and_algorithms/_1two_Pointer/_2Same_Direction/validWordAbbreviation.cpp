#include <bits/stdc++.h>
using namespace std;
// brute force
bool validWordAbbreviation(string word, string abbr)
{
    // Expand abbreviation into a vector with wildcards
    vector<char> expanded;
    int j = 0;

    while (j < abbr.size())
    {
        char c = abbr[j];
        if (isalpha(c))
        {
            expanded.push_back(c);
            j++;
        }
        else
        {
            // Leading zero check
            if (c == '0')
                return false;
            // Parse the full number
            int num = 0;
            while (j < abbr.size() && isdigit(abbr[j]))
            {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            // Add wildcards for skipped characters
            for (int k = 0; k < num; k++)
            {
                expanded.push_back('*');
            }
        }
    }

    // Length must match
    if (expanded.size() != word.size())
        return false;

    // Compare character by character
    for (int i = 0; i < word.size(); i++)
    {
        if (expanded[i] != '*' && expanded[i] != word[i])
        {
            return false;
        }
    }
    return true;
}

// optimal
bool validWordAbbreviation(string word, string abbr)
{
    int i = 0; // pointer for word
    int j = 0; // pointer for abbreviation

    while (i < (int)word.size() && j < (int)abbr.size())
    {
        if (isdigit(abbr[j]))
        {
            // Leading zero is not allowed
            if (abbr[j] == '0')
                return false;

            // Parse the full number
            int num = 0;
            while (j < (int)abbr.size() && isdigit(abbr[j]))
            {
                num = num * 10 + (abbr[j] - '0');
                j++;
            }
            // Skip that many characters in word
            i += num;
        }
        else
        {
            // Letters must match exactly
            if (word[i] != abbr[j])
                return false;
            i++;
            j++;
        }
    }

    // Both pointers must reach the end
    return i == (int)word.size() && j == (int)abbr.size();
}