#include <bits/stdc++.h>
using namespace std;
// kono binary number er shthe 1 AND krle jdi true hy tahole bujte hbe oita odd number
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

    for (int i = 0; i < 8; ++i)
    {
        printBinary(i);

        if (i & 1) // i%2!=0 ..eita slow.. % and / slow operation in bit
        {
            cout << "odd\n";
        }
        else
        {
            cout << "even\n";
        }
    }

    return 0;
}