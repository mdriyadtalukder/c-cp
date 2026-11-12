
#include <bits/stdc++.h>
using namespace std;

// brute force
string countAndSay(int n)
{
    if (n == 1)
        return "1";

    string say = countAndSay(n - 1);

    // Processing
    string result = "";

    for (int i = 0; i < say.length(); i++)
    {
        char ch = say[i];
        int count = 1;
 
        while (i < say.length() - 1 && say[i] == say[i + 1]) //i < say.length() - 1 ..-1 for safty of say(i+1)
        {
            count++;
            i++;
        }

        result += to_string(count) + string(1, ch);
    }

    return result;
}

// optimal

string countAndSay(int n)
{
    string say = "1";

    for (int k = 1; k < n; k++)
    {
        string result = "";

        for (int i = 0; i < say.size(); i++)
        {
            char ch = say[i];
            int count = 1;

        while (i < say.length() - 1 && say[i] == say[i + 1])
            {
                count++;
                i++;
            }

            result += to_string(count) + string(1, ch); ////i < say.length() - 1 ..-1 for safty of say(i+1)
        }

        say = result;
    }

    return say;
}
