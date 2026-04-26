// set mane 1..unset mane 0
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
    printBinary(9); // 9 ke binary te convert

    int a = 9; // example number
    int i = 3;

    if ((a & (1 << i)) != 0)
    { // a=9 er 3 no bit 1 nki orthat set nki ta check kora...0101 last ta 0th no bit then 1st..so on
        cout << "set bit\n";
    }
    else
    {
        cout << "not set bit\n";
    }

    // bit set
    printBinary(a | (1 << 1)); // 9 er 1st  bit ke set bit kra ..orthat 1 kora

    // bit unset
    printBinary(a & (~(1 << 3))); ////9 er 3rd  bit ke unset bit kra ..orthat 0 kora

    // toggle
    printBinary(a ^ (1 << 2)); // 9 er 2nd no bit 0 thakle 1 krbe or 1 thkle 0 krbe
    printBinary(a ^ (1 << 3)); // 9 er 3rd no bit 0 thakle 1 krbe or 1 thkle 0 krbe

    int setCount = 0, unSetCount = 0, b = 10;
    for (int i = 31; i >= 0; --i) // 10 er binary te koita set ase r koita unset ase ta count krbe
    {
        if ((b & (1 << i)) != 0)
        {
            setCount++;
        }
        else
        {
            unSetCount++;
        }
    }
    cout << setCount << endl;
    cout << unSetCount << endl;
    cout << __builtin_popcount(a) << endl;         // set count kre..built in function
    cout << __builtin_popcountll((1LL << 35) - 1); // set count kre for long long data

    return 0;
}