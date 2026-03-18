#include <bits/stdc++.h>
using namespace std;
// binary to decimal 1011=1*2^3+0*2^2+1*2^1+1*2^0=2^3+2^1+2^0//0 er ta bad jabe.

int binaryToDecimal(string binary)
{
    int n = binary.size(); // fixed
    int p = 1;             // fixed
    int decimal = 0;

    for (int i = n - 1; i >= 0; i--)
    { // fixed ';'
        if (binary[i] == '1')
        {
            decimal += p;
        }
        p *= 2;
    }

    return decimal; // fixed return
}

int main()
{
    string n; // should be string, not int
    cin >> n; // fixed ';'

    cout << binaryToDecimal(n);

    return 0;
}