#include <bits/stdc++.h>
using namespace std;
// brute force
int lengthOfLastWord(string s)
{
    // The stream extractor skips over any run of whitespace, so only real words come out
    istringstream iss(s);
    vector<string> words;
    string word;

    /*  string s = "Hello World";
      istringstream iss(s);

      string word;

      iss >> word; // Hello
      iss >> word; // World     extract word and push to words*/
    while (iss >> word)
    {
        words.push_back(word);
    }

    if (words.empty())
    {
        return 0;
    }

    return words.back().size(); //get last value
}

// optimal
int lengthOfLastWord2(string s)
{

    int c = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' && c == 0)
            continue;
        else if (s[i] == ' ' && c > 0)
            break;
        else
            c++;
    }
    return c;
}