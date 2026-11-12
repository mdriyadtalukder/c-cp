
#include <bits/stdc++.h>
using namespace std;

int MAX_WIDTH;

// Find and create a fully justified line
string findLine(int i, int j, int eachGaddhaSpace,
                int extraSpaceGaddha, vector<string>& words)
{
    string line;

    for (int k = i; k < j; k++)
    {
        line += words[k];

        // No space after the last word
        if (k == j - 1)
            continue;

        // Add equal spaces between words
        for (int z = 0; z < eachGaddhaSpace; z++)
        {
            line += " ";
        }

        // Distribute extra spaces from left to right
        if (extraSpaceGaddha > 0)
        {
            line += " ";
            extraSpaceGaddha--;
        }
    }

    // Add remaining spaces at the end
    while (line.length() < MAX_WIDTH)
    {
        line += " ";
    }

    return line;
}

vector<string> fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> result;

    int n = words.size();
    MAX_WIDTH = maxWidth;

    int i = 0;

    while (i < n)
    {
        int lettersCount = words[i].length();

        int j = i + 1;
        int gaddhe = 0;

        // Find how many words can fit in this line
        while (j < n &&
               words[j].length() + 1 + gaddhe + lettersCount <= maxWidth)
        {
            lettersCount += words[j].length();
            gaddhe++;
            j++;
        }

        int remainingGaddhe = maxWidth - lettersCount;

        int eachGaddhaSpace = (gaddhe == 0)
                                  ? 0
                                  : remainingGaddhe / gaddhe;

        int extraSpaceGaddha = (gaddhe == 0)
                                   ? 0
                                   : remainingGaddhe % gaddhe;

        // Last line: left justified
        if (j == n)
        {
            eachGaddhaSpace = 1;
            extraSpaceGaddha = 0;
        }

        result.push_back(
            findLine(i, j, eachGaddhaSpace, extraSpaceGaddha, words)
        );

        i = j;
    }

    return result;
}


