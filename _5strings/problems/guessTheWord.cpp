#include <bits/stdc++.h>
using namespace std;
int match(const string &a, const string &b)
{
    int count = 0;

    for (int i = 0; i < 6; i++)
    {
        if (a[i] == b[i])
            count++;
    }

    return count;
}

void findSecretWord(vector<string> &words, Master &master)
{

    vector<string> candidates = words;

    while (!candidates.empty())
    {

        string guess = candidates[0];
        int best = INT_MAX;

        // find guess
        for (string &g : candidates)
        {
           
            int count[7] = {};

            //take one g and compare with all candidates  to find out matches
            for (string &w : candidates)
            {
                count[match(g, w)]++;
                /*example:
           count[0] = 2; // 2 words have 0 matching positions
           count[1] = 2; // 2 words have 1 matching position
           count[2] = 3; // 3 words have 2 matching positions*/
            }

            int worst = 0;

            for (int i = 0; i <= 6; i++)
            {
                worst = max(worst, count[i]);
            }

            if (worst < best)
            {
                best = worst;
                guess = g;
            }
        }

        // apply guess
        int matches = master.guess(guess);

        if (matches == 6)
        {
            return;
        }

        // filtering
        vector<string> filtered;

        for (string &word : candidates)
        {
            if (match(word, guess) == matches)
            {
                filtered.push_back(word);
            }
        }

        candidates = filtered;
    }
}