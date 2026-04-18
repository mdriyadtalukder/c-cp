// with replacement..k bar replce krte parbo oi same number bananor jnoo..like 2 3 3 4..k=1 s0 3 3 3 4...lentgh=3
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k)
{
    int freq[26] = {0};
    int left = 0, maxFreq = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++)
    {
        freq[s[right] - 'A']++;
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        while ((right - left + 1) - maxFreq > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    string s = "AABABBA"; // test case
    int k = 1;

    cout << characterReplacement(s, k) << endl;

    return 0;
}