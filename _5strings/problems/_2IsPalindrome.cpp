#include <bits/stdc++.h>
using namespace std;
//brute force
bool isPalindrome(string s)
{
    string a, b;
    for (auto i : s)
    {
        if ((i >= 'a' && i <= 'z') || i >= 'A' && i <= 'Z' || isdigit(i)) // isalnum(i)-> both checking
        {
            a.push_back(tolower(i));
        }
    }
    b = a;
    reverse(a.begin(), a.end());
    return a == b;
}

// optimal
bool isPalindrome2(string s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters from the left
        if (!isalnum(s[left]))
        {
            left++;
            continue;
        }
        // Skip non-alphanumeric characters from the right
        if (!isalnum(s[right]))
        {
            right--;
            continue;
        }

        // Compare lowercase versions
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    // string s = "0P";
    cout << isPalindrome(s);
}