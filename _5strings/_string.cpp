#include <iostream>
#include <string> // for std::string
#include <algorithm>
using namespace std;

int main()
{
    // total 14 method

    // 1. Create a string
    string str = "Hello", s;
    cin.ignore();    // ignore the leftover newline
    cin >> s;        // take a word..like 'hello'
    getline(cin, s); // take lines
    cout << "Original string: " << str << endl;

    // 2. Append to string
    str += " World"; // Adds to the end of string
    cout << "After append: " << str << endl;
    cout << "Length of string: " << str.length() << endl;

    // 3. Insert into string
    str.insert(5, ","); // Insert "," at index 5
    cout << "After insert: " << str << endl;
    cout << "Length of string: " << str.length() << endl;

    // 4. Erase from string
    str.erase(5, 1); // Remove 1 character at index 5
    cout << "After erase: " << str << endl;

    // 5. Replace substring
    str.replace(6, 5, "C++"); // Replace 5 chars from index 6 with "C++"
    cout << "After replace: " << str << endl;

    // 6. Access characters
    cout << "Character at index 1: " << str[1] << endl;
    cout << "Character at index 1: " << toupper(str[1]) << endl;
    cout << "Character at index 1: " << tolower(str[1]) << endl;

    // 7. Find substring
    size_t pos = str.find("C++"); // Returns starting index of substring
    if (pos != string::npos)
    {
        cout << "\"C++\" found at index: " << pos << endl;
    }

    // 8. Substring
    string sub = str.substr(6, 3); // Extract 3 chars from index 6
    cout << "Substring: " << sub << endl;

    // 9. Length / size
    cout << "Length of string: " << str.length() << endl;
    cout << "Size of string: " << str.size() << endl; // same as length()

    // 10. Empty check
    if (str.empty())
    {
        cout << "String is empty" << endl;
    }
    else
    {
        cout << "String is not empty" << endl;
    }

    // 11. Clear string
    string temp = "Temp string";
    temp.clear(); // Remove all contents
    cout << "After clear, temp size: " << temp.size() << endl;

    // 12. Compare strings
    string a = "abc";
    string b = "abd";
    if (a.compare(b) == 0)
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        cout << "Strings are different" << endl;
    }

    // 13. Iterating through string
    cout << "Characters in str: ";
    for (char c : str)
    {
        cout << c << " ";
    }
    cout << endl;

    // 14. Convert string to C-style string (char array)..make a array with string's characters
    const char *cstr = str.c_str();
    cout << "C-style string: " << cstr << endl;
    cout << cstr[0];

    // 14
    string s = "abc";

    next_permutation(s.begin(), s.end());
    cout << s << endl; // acb

    prev_permutation(s.begin(), s.end());
    cout << s << endl; // abc

    //
    s.push_back('.');
    s.pop_back();

    return 0;
}
