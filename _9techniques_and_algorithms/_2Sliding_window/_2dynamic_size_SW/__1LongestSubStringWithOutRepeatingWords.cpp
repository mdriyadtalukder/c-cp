#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int maxN = 0;
    unordered_set<char> m;
    int left = 0;

    for (int right = 0; right < s.size(); right++)
    {
        while (m.count(s[right])) // j porjon right ta delete na hbe oi porjonto left theke delete hote thkbe..
        {
            m.erase(s[left]);
            left++;
        }
        m.insert(s[right]);
        maxN = max(maxN, right - left + 1);
    }

    return maxN;
}

int main()
{
    string s = "abba"; // hardcoded test case
    cout << lengthOfLongestSubstring(s);
    return 0;
}