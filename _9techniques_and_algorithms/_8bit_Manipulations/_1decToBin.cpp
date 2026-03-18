// deciman (0-9) to binary(0-1)-->num k 2 dara vag krbo until vag sesh 0 na hoy..then nich theke remind nibo.. fake thke 0 dite hbe..
#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n)
{
    string binary = "";

    while (n != 0)
    {
        int rem = n % 2; // fixed '='
        binary += to_string(rem);
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int main()
{
    int n;
    cin >> n;

    cout << decimalToBinary(n);

    return 0;
}