#include <bits/stdc++.h>
using namespace std;

// bruteforce
int countBinarySubstrings(string s)
{
    // Step 1: Build group sizes array
    vector<int> groups;
    int i = 0;
    int n = s.size();

    while (i < n)
    {
        char ch = s[i];
        int groupSize = 0;
        while (i < n && s[i] == ch)
        {
            groupSize++;
            i++;
        }
        groups.push_back(groupSize);
    }

    // Step 2: Sum min of adjacent pairs
    int count = 0;
    for (int j = 0; j < (int)groups.size() - 1; j++)
    {
        count += min(groups[j], groups[j + 1]);
    }

    return count;
}
// optimal
int countBinarySubstrings(string s)
{
    int result = 0;
    int prevCount = 0;
    int currCount = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            currCount++;
        }
        else
        {
            result += min(prevCount, currCount);
            prevCount = currCount;
            currCount = 1;
        }
    }

    return result + min(prevCount, currCount);
}