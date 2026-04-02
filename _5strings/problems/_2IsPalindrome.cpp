#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s)
{
    string a, b;
    for (auto i : s)
    {
        if ((i >= 'a' && i <= 'z') || i >= 'A' && i <= 'Z' || isdigit(i))
        {
            a.push_back(tolower(i));
        }
    }
    b = a;
    reverse(a.begin(), a.end());
    return a == b;
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    // string s = "0P";
    cout << isPalindrome(s);
}