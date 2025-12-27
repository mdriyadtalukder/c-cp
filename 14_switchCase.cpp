#include <iostream>
using namespace std;
main()
{
    char c;
    cin >> c;
    c = tolower(c);
    switch (c)
    {
    case 'a':
    case 'i':
    case 'e':
    case 'o':
    case 'u':
        cout << "Vowel";
        break; //every case er por break hbe except default

    default:
        cout << "Consonant";
    }
}