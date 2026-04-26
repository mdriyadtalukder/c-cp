// i=4 so 0-4th bit er sob unset krbe mane 0 banabe..LSB (Least Significant Bit)
// i=4 so last theke 4+1=5 porjonto sob 0 hbe..MSB (Most Significant Bit)
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
    printBinary(59);
    int a = 59;
    int i = 4, b = (a & (~((1 << (i + 1)) - 1)));
    printBinary(b);
    // MSB
    i = 4;
    int c = (a & ((1 << (i + 1)) - 1));
    printBinary(c);
}