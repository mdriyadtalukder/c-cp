// upper case e 5th bit set hy na..but lower e 5th bit set hy
#include <bits/stdc++.h>
using namespace std;
void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

int main()
{

    for (char c = 'A'; c <= 'E'; ++c)
    {
        cout << c << endl;
        printBinary(int(c));
    }
    for (char c = 'a'; c <= 'e'; ++c)
    {
        cout << c << endl;
        printBinary(int(c));
    }
    char A = 'A';
    char a = A | (1 << 5); // A ke lowercase e banaise..5th bit e set kore ba 1 baniye
    cout << a << endl;

    // tricks
    char B = 'B';
    // uppercase to lowercase
    char b = B | ' ';
    cout << b << endl;
    // lowercase to uppercase
    char d = 'd';
    char D = (d & '_');
    cout << D << endl;

    return 0;
}