#include <bits/stdc++.h>
using namespace std;

int index = 0;

string decode(const string &s)
{
    string result;

    while (index < s.size() && s[index] != ']')
    {
        if (isdigit(s[index]))
        {
            // Parse the full number
            int num = 0;
            while (index < s.size() && isdigit(s[index]))
            {
                num = num * 10 + (s[index] - '0');
                index++;
            }
            index++;                    // Skip '['
            string decoded = decode(s); // Recursively decode inner content
            index++;                    // Skip ']'
            // Repeat and append
            for (int i = 0; i < num; i++)
            {
                result += decoded;
            }
        }
        else
        {
            // Regular character
            result += s[index];
            index++;
        }
    }

    return result;
}

string decodeString(string s)
{
    index = 0;
    return decode(s);
}
int main()
{
    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    string result = decodeString(s);

    cout << "Decoded string: " << result << endl;

    return 0;
}