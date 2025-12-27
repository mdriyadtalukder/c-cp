#include <iostream>
using namespace std;
main()
{
    char l;
    cout << "Write a letter";
    cin >> l;
    l = tolower(l);
    // l=toupper(l)
    if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
    {
        cout << "Consonant";
    }
    else
    {
        cout << "Vowel";
    }
}