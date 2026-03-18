#include <bits/stdc++.h>
using namespace std;

string twosComplement(string binary)
{
    int n = binary.size();

    // Step 1: 1's complement (flip bits)
    for (int i = 0; i < n; i++)
    {
        if (binary[i] == '0')
            binary[i] = '1';
        else
            binary[i] = '0';
    }

    // Step 2: add 1
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (binary[i] == '1' && carry == 1)
        {
            binary[i] = '0';
        }
        else if (binary[i] == '0' && carry == 1)
        {
            binary[i] = '1';
            carry = 0;
        }
    }

    return binary;
}

int main()
{
    string binarys;
    cin >> binarys;

    cout << twosComplement(binarys);

    return 0;
}